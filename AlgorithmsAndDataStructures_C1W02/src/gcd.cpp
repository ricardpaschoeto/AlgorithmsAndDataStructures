#include <iostream>
#include <cassert>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b)
{
    int ap = 0;
    if (b == 0)
        return a;
    ap = a % b;
    return gcd_fast(b, ap);
}

void test_gcd()
{
    assert(gcd_fast(18, 35) == 1);
    assert(gcd_fast(28851538, 1183019) == 17657);    
}
