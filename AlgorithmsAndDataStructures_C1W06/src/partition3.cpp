#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using std::vector;

int partition3(vector<int> &A) {
    
    int n = A.size();
    int sum = std::accumulate(A.begin(), A.end(), 0);

    if (A.size() < 3)
        return 0;
    if (sum % 3 != 0)
        return 0;

    sum /= 3;

    std::vector<std::vector<int> > dp(n, std::vector<int>(sum + 1, 0));
    for (size_t i = 0; i < n; i++)
    {
        dp[i][0] = 0;
    }

    for (size_t s = 1; s <= sum; s++)
    {
        if (A[s] == 0)
            dp[0][s] = 1;
        else
            dp[0][s] = 0;
    }

    for (size_t i = 1; i < n; i++){
        for (size_t s = 1; s <= sum; s++)
        {
            if (dp[i - 1][s]) {
                dp[i][s] = dp[i - 1][s];
            }
            else if (s >= A[i]) {
                dp[i][s] = dp[i - 1][s - A[i]];
            }
        }
    }

    return dp[n-1][sum];
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
