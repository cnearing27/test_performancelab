#include <iostream>
#include <fstream>

using namespace std;

unsigned int	ft_atoi(string	str, int	j)
{
	unsigned int	num;
	int				i;

	i = j;
	num = 0;
	if (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}

int	count_args(string	values)
{
	int	i = 0, count = 0, length;

	length  = values.length();
	while (i < length - 1)
	{
		if (values[i] == '"')
			if (values[i + 1] == 'i')
				if (values[i + 2] == 'd')
					if (values[i + 3] == '"')
					{
						count++;
						i += 3;
					}
		i++;
	}
	return (count);
}

int main()
{
	string 			tests, values, current, curr_mark;
	int				i, j, length, number_of_args;
	unsigned int	curr_id;
	ifstream		file1;
	ofstream		result;

	file1.open("tests.json");
	while (!file1.eof())
	{
		getline(file1, current);
		if (!current.empty())
		{
			tests += current + '\n';
			current.clear();
		}
	}
	file1.close();
	file1.open("values.json");
	while (!file1.eof())
	{
		getline(file1, current);
		if (!current.empty())
		{
			values += current + '\n';
			current.clear();
		}
	}
	file1.close();
	number_of_args = count_args(values);

	unsigned int	ids[number_of_args];
	string			marks[number_of_args];

	i = 0;
	j = 0;
	length = values.length();
	while (i < length)
	{
		if (values[i] == '"')
			if (values[i + 1] == 'i')
				if (values[i + 2] == 'd')
					if (values[i + 3] == '"')
					{
						ids[j] = ft_atoi(values, i + 6);
						i += 6;
					}
		if (values[i] == '"')
			if (values[i + 1] == 'v')
				if (values[i + 2] == 'a')
					if (values[i + 3] == 'l')
						if (values[i + 4] == 'u')
							if (values[i + 5] == 'e')
									if (values[i + 6] == '"')
									{
										marks[j] = values.substr(i + 10, values.find('"', i + 10) - i - 10);
										i += 14;
										j++;
									}
		i++;
	}
	length = tests.length();
	i = 0;
	result.open("report.json");
	while (i < length)
	{
		if (tests[i] == '"')
		{
			if (tests[i + 1] == 'i')
				if (tests[i + 2] == 'd')
					if (tests[i + 3] == '"')
					{
						result << "\"id";
						curr_id = ft_atoi(tests, i + 6);
						j = 0;
						while (j < number_of_args)
						{
							if (ids[j] == curr_id)
								break ;
							j++;
						}
						if (j < number_of_args)
							curr_mark = marks[j];
						i += 3;
					}
			if (tests[i + 1] == '"')
				{
					result << "\"" << curr_mark;
					i++;
				}
			result << "\"";
		}
		else
			result << tests[i];
		i++;
	}
	result.close();
	return 0;
}
