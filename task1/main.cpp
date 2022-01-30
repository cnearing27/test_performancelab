#include <iostream>

using namespace std;

int main()
{
	int	n, m, i, j;

	cin >> n >> m;

	int	arr[n];

	i = 0;
	while (i < n)
	{
		arr[i] = i + 1;
		i++;
	}
	i = 0;

	int	arr2[m];

	j = 0;
	while (arr2[m - 1] != 1)
	{
		if (i == n)
			i = 0;
		if (j == m)
		{
			i--;
			j = 0;
		}
		arr2[j] = arr[i];
		if (j == 0)
			cout << arr2[j];
		i++;
		j++;
	}
	cout << endl;
	return 0;
}
