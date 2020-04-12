#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using std::vector;
using std::swap;

//vector<int> partition3(vector<int> &a, int l, int r) {
//  int v = a[r];
//  int i = l-1;
//  int j = r;
//  int p = l-1;
//  int q = r;
//  vector<int> res;
//  for (;;)
//  {
//      while (a[++i] < v);
//      while (v < a[--j]) if (j == l) break;
//      if (i >= j) break;
//      swap(a[i], a[j]);
//      if (a[i] == v) { p++; swap(a[p], a[i]); }
//      if (v == a[j]) { q--; swap(a[j], a[q]); }
//  }
//
//  swap(a[i], a[r]); j = i - 1; i = i + 1;
//  for (int k = l; k < p; k++, j--) swap(a[k], a[j]);
//  for (int k = r - 1; k > q; k--, i++) swap(a[i], a[k]);
//
//  res.push_back(j);
//  res.push_back(i);
//
//  return res;
//}

vector<int> partition3(vector<int>& a, int l, int r) {

    vector<int> res;
    int i = l, k = l, p = r;
    while (i < p) {
        if (a[i] < a[r]) swap(a[i++], a[k++]);
        else if (a[i] == a[r]) swap(a[i], a[--p]);
        else i++;
    }
    
    int m = fmin(p - k, r - p + 1);

    for (int q = 0; q < m; q++) swap(a[k + q], a[r - m + 1 + q]);
    
    res.push_back(k);
    res.push_back(r-p+k);

    return res;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[r], a[k]);
  vector<int> m = partition3(a, l, r);

  randomized_quick_sort(a, l, m[0] - 1);
  randomized_quick_sort(a, m[1] + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
