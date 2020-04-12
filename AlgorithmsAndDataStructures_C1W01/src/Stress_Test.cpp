#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using std::vector;
using std::cin;
using std::cout;

extern int64_t MaxPairwiseProductFast(const vector<int>&);
extern int64_t MaxPairwiseProduct(const vector<int>&);

void StressTest(int N, int M)
{

	while (true)
	{
		int n = rand() % N + 2;
		vector<int> numbers(n);
		for (int i = 0; i < n; ++i) {
			numbers[i] = rand() % M;
		}

		for (int i = 0; i < n; i++)
		{
			std::cout << numbers[i] << " ";
		}

		std::cout << std::endl;

		int64_t result1 = MaxPairwiseProduct(numbers);
		int64_t result2 = MaxPairwiseProductFast(numbers);

		if (result1 == result2)
		{
			std::cout << "OK" << std::endl;
		}
		else
		{
			std::cout << "WRONG ANSWER: " << result1 << "," << result2 << std::endl;
			return;
		}

	}

}