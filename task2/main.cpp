#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	string	filename1, filename2, info;
	int		pos;
	float	x0, y0, x1, y1, r;

	cin >> filename1 >> filename2;
	ifstream file1;
	file1.open(filename1);
	getline(file1, info);
	pos = info.find(' ');
	x0 = stof(info.substr(0, pos));
	y0 = stof(info.substr(pos + 1));
	getline(file1, info);
	r = stof(info);
	file1.close();
	file1.open(filename2);
	while (!file1.eof())
	{
		getline(file1, info);
		if (info.empty())
			break ;
		pos = info.find(' ');
		x1 = stof(info.substr(0, pos));
		y1 = stof(info.substr(pos + 1));
		if ((x0 - x1)*(x0 - x1) + (y0 - y1)*(y0 - y1) < r*r)
			cout << 1 << endl;
		else if ((x0 - x1)*(x0 - x1) + (y0 - y1)*(y0 - y1) > r*r)
			cout << 2 << endl;
		else
			cout << 0 << endl;
	}
	file1.close();
	return 0;
}
