#include <iostream>
#include <vector>
#include <cassert>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n)
{
    if(n <= 1)
         return n;

    std::vector<int> Fn(n + 1);
    Fn[0] = 0;
    Fn[1] = 1;

    for (size_t i = 2; i < Fn.size(); i++)
    {
        Fn[i] = (Fn[i - 1] + Fn[i - 2]) % 10;
    }

    return Fn[n];
}

void test_fibonacci_last_digit()
{
    assert(get_fibonacci_last_digit_fast(3) == 2);
    assert(get_fibonacci_last_digit_fast(331) == 9);
    assert(get_fibonacci_last_digit_fast(327305) == 5);

    int n = 10e7;
    for (size_t i = 0; i <= n; i++)
    {
        //std::cout << i << std::endl;
        assert(get_fibonacci_last_digit_fast(i) == get_fibonacci_last_digit_naive(i));
    }
}


