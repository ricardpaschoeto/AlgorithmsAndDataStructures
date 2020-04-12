#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
    vector<int> sequence;
    vector<int> factors{ 1,2,3 };
    vector<int> MinNumOps(n + 1);
    MinNumOps[0] = 0;
    int NumOps = 0;
    int pos = n;

    for (size_t m = 1; m <= n; m++)
    {
        MinNumOps[m] = std::numeric_limits<int>::max();
        for (size_t i = 0; i < factors.size(); i++)
        {
            if (factors[i] != 1)
            {
                if (m % factors[i] == 0) {
                    if((m / factors[i]) == 1)
                        NumOps = MinNumOps[(m/factors[i])-1] + 1;
                    else
                        NumOps = MinNumOps[(m / factors[i])] + 1;
                    if (NumOps < MinNumOps[m])
                    {
                        MinNumOps[m] = NumOps;
                    }
                }
            }
            else
            {
                NumOps = MinNumOps[(m - factors[i])] + 1;
                if (NumOps < MinNumOps[m])
                {
                    MinNumOps[m] = NumOps;
                }
            }
        }
    }
    sequence.push_back(pos);
    while (pos > 1)
    {
        if (MinNumOps[pos] > MinNumOps[pos - 1]) {
            pos -= 1;
            sequence.push_back(pos);
        }
        if (pos % 3 == 0) {
            pos /= 3;
        }
        else if (pos % 2 == 0) {
            pos /= 2;
        }
        else {
            pos -= 1;
        }
        sequence.push_back(pos);
    }
    std::reverse(sequence.begin(), sequence.end());
    return sequence;
}

//int main() {
//  int n;
//  std::cin >> n;
//  vector<int> sequence = optimal_sequence(n);
//  std::cout << sequence.size() - 1 << std::endl;
//  for (size_t i = 0; i < sequence.size(); ++i) {
//    std::cout << sequence[i] << " ";
//  }
//}
