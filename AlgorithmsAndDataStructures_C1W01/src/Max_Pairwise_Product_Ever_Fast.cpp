#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int64_t MaxPairwiseProductEverFast(vector<int>& numbers)
{
	int index = 0;
	int n = numbers.size();
	for (size_t i = 1; i < n; i++)
	{
		if (numbers[i] > numbers[index])
			index = i;
	}
	std::swap(numbers[index], numbers[n-1]);

	index = 0;
	for (size_t i = 1; i < n-1; i++)
	{
		if (numbers[i] > numbers[index])
			index = i;
	}
	std::swap(numbers[index], numbers[n-2]);

	return (int64_t)numbers[n-2] * numbers[n - 1];

}