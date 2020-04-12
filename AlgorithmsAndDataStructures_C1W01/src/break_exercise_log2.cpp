#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

extern void mergeSort(vector<int>&, int, int);

vector<int> FindTwoMaxLog2(vector<int>& numbers)
{
	int n = numbers.size();

	vector<int> result(2);
	vector<int> odd;
	vector<int> even;

	if (n % 2 == 0) {
		odd.resize(n / 2);
		even.resize(n / 2);
	}
	else
	{
		odd.resize(n / 2);
		even.resize(n / 2 +1);
	}

	for (size_t i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			even[i / 2] = numbers[i];
		}
		else
		{
			odd[(i - 1) / 2] = numbers[i];
		}
	}

	mergeSort(even, 0, even.size() - 1);
	mergeSort(odd, 0, odd.size() - 1);

	result[0] = even[even.size() - 1];
	result[1] = odd[odd.size() - 1];

	return result;

}