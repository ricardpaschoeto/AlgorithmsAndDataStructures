#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int get_change(int money) {
    std::vector<int> coins{ 1,3,4 };
    std::vector<int> MinNumCoins(money + 1);
    MinNumCoins[0] = 0;
    int NumCoins = 0;
    for (size_t m = 1; m <= money; m++)
    {
        MinNumCoins[m] = std::numeric_limits<int>::max();
        for (size_t i = 0; i < coins.size(); i++)
        {
            if (m >= coins[i])
            {
                NumCoins = MinNumCoins[m - coins[i]] + 1;
                if (NumCoins < MinNumCoins[m])
                {
                    MinNumCoins[m] = NumCoins;
                }
            }
        }
    }
    return MinNumCoins[money];
}

//int main() {
//  int m;
//  std::cin >> m;
//  std::cout << get_change(m) << '\n';
//}
