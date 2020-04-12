#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int64_t MaxPairwiseProductFast(const vector<int>& numbers)
{
	int index1 = 0;
	int index2;

	int n = numbers.size();

	for (int i = 1; i < n; i++) 
	{
		if (numbers[i] > numbers[index1])
			index1 = i;
	}

	if (index1 == 0)
		index2 = 1;
	else
		index2 = 0;

	for (int i = 1; i < n; i++)
	{
		if ((i != index1) && (numbers[i] > numbers[index2]))
			index2 = i;
	}

	return (int64_t)numbers[index1] * numbers[index2];
}
