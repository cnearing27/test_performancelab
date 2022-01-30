#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>

using namespace std;

int	ft_atoi(string	str, int	i)
{
	int				sign;
	long long int	num;

	num = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		if (num < 0 && sign == -1)
			return (0);
		if (num < 0 && sign == 1)
			return (-1);
		i++;
	}
	return (num * sign);
}

int main()
{
	string	filename, current, nums = "";
	int		i = 0, count = 0, result = 0;

	cin >> filename;
	ifstream file1;
	file1.open(filename);
	while (!file1.eof())
	{
		file1 >> current;
		if (!current.empty())
		{
			nums += current + ' ';
			current.clear();
			count++;
		}
	}

	int	numbers[count], median = 0, j = 0;

	while (nums[i])
	{
		numbers[j] = ft_atoi(nums, i);
		median += numbers[j];
		j++;
		if (nums[i] == '-')
			i++;
		while (nums[i] >= '0' && nums[i] <= '9')
			i++;
		while (nums[i] == ' ')
			i++;
	}
	median = round((float)median / (float)count);
	i = 0;
	while (i < count)
	{
		while (numbers[i] < median)
		{
			numbers[i]++;
			result++;
		}
		while (numbers[i] > median)
		{
			numbers[i]--;
			result++;
		}
		i++;
	}
	cout << result << endl;
	file1.close();
	return 0;
}
