#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

int optimal_weight(int W, const vector<int>& w) {
    //write your code here
    std::vector<std::vector<int> > value(W+1, std::vector<int>(w.size()+1,0));
    int val = 0;

    for (size_t j = 1; j <= w.size(); ++j) {
        for (size_t wind = 1; wind <= W; wind++)
        {
            if (w[j-1] > wind)
                value[wind][j] = value[wind][j - 1];
            else
                value[wind][j] = std::max(value[wind][j - 1], value[wind - w[j-1]][j - 1] + w[j-1]);
        }
    }
    return value[W][w.size()];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
