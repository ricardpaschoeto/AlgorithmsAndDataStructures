#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using std::vector;
using std::cin;
using std::cout;

extern vector<int> FindTwoMaxLog2(vector<int>&);

int main() {

    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    vector<int> result = FindTwoMaxLog2(numbers);
    cout << result[0] << "\n";
    cout << result[1] << "\n";
    return 0;
}