#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
 

int64_t MaxPairwiseProduct(const vector<int>& numbers) {
  int64_t result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
        int64_t temp = (int64_t)numbers[i] * numbers[j];
        result = std::fmax(result, temp);
    }
  }
  return result;
}


