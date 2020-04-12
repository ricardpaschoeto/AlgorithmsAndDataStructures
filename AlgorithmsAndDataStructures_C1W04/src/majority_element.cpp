#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>

using std::vector;

int binary_search(const vector<int>& a, int x) {
    int left = 0, right = (int)a.size() - 1;
    while (left <= right)
    {
        int mid = floor(left + (right - left) / 2);
        if (x == a[mid])
            return mid;
        else if (x < a[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int get_majority_element(vector<int> &a, int left, int right) {
    int n = a.size();
    std::sort(a.begin(), a.end());
    int i = 0;
    while (i < n)
    {
        int ind = binary_search(a, a[i]);

        int count = 1;
        left = ind - 1;
        while (left >= 0 && a[left] == a[i]) {
            count++; left--;
        }

        right = ind + 1;
        while (right < a.size() && a[right] == a[i]) {
            count++; right++;
        }
        i = right;

        if (count > n / 2)
            return 1;
    }
    return -1;

}

//int main() {
//  int n;
//  std::cin >> n;
//  vector<int> a(n);
//  for (size_t i = 0; i < a.size(); ++i) {
//    std::cin >> a[i];
//  }
//  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
//}
