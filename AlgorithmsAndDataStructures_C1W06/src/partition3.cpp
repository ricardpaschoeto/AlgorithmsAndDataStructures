#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

int optimal_sum(int K, const vector<int>& w) {
    std::vector<std::vector<int> > value(K + 1, std::vector<int>(w.size() + 1, 0));
    int k = w.size() / 3;
    int val = 0;

    for (size_t j = 1; j <= w.size(); ++j) {
        for (size_t wind = 1; wind <= k; wind++)
        {
            if (w[j - 1] > wind)
                value[wind][j] = value[wind][j - 1];
            else
                value[wind][j] = std::max(value[wind][j - 1], value[wind - w[j - 1]][j - 1] + w[j - 1]);
        }
        if (value[wind][j] != 0 && value[wind][j] % K == 0)
            
    }
    return value[K][w.size()];
}

int partition3(vector<int> &A) {
    if (A.size() == 3)
        return 1;
    if (A.size() < 3)
        return 0;
    int res = optimal_sum(3, A);
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
