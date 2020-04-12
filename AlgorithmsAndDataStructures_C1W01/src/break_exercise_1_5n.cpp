#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> FindTwoMax15n(vector<int>& numbers)
{
	vector<int> result(1);
	int n = numbers.size();

	for (size_t i = 0; i < n/2; i++)
	{
		if (numbers[2 * i] > numbers[2 * i + 1])
			std::swap(numbers[2 * i], numbers[2 * i + 1]);
	}

	int index = 0; 
	for (size_t i = 0; i <= n/2; i++)
	{
		if (numbers[2*i] > numbers[index])
			index = 2*i;
	}

	result.push_back(numbers[index]);

	index = 0;
	for (size_t i = 0; i < n / 2; i++)
	{
		if (numbers[2*i+1] > numbers[index])
			index = 2 * i + 1;
	}

	result.push_back(numbers[index]);

	return result;
	
}