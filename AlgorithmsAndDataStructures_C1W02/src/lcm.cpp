#include <iostream>
#include <cassert>
#include <time.h>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int64_t lcm_fast(int a, int b)
{
    int64_t lcm = 1;
    int div = 2;
    int atemp = a;
    int btemp = b;

    while (true)
    {
        if (atemp % div == 0 || btemp % div == 0)
        {
            lcm *= div;
            if (atemp % div == 0)
                atemp /= div;
            if (btemp % div == 0)
                btemp /= div;
        }
        else if (atemp % div != 0 && btemp % div != 0)
        {
            div++;
        }

        if (atemp == 1 && btemp == 1)
            return lcm;
    }

}

void test_lcm_fast()
{
    int a = 2345678901;
    int b = 1234567893;
    assert(lcm_fast(a, b) == lcm_naive(a, b));

}