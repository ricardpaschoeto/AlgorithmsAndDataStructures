#include <iostream>
#include <vector>

// Fibonacci
extern int fibonacci_naive(int);
extern int fibonacci_fast(int);
extern void test_solution();
// Fibonacci Last Digit
extern int get_fibonacci_last_digit_naive(int);
extern int get_fibonacci_last_digit_fast(int);
extern void test_fibonacci_last_digit();
// GCD
extern int gcd_naive(int, int);
extern int gcd_fast(int, int);
extern void test_gcd();
// LCM
extern long long lcm_naive(int, int);
extern long long lcm_fast(int, int);
extern void test_lcm_fast();
// Fibonacci mod m
extern void lcm_fast_factors(int, int, std::vector<int>&);
extern void powers(std::vector<int>&);
extern int64_t pisanoPeriod(int);
extern void test_pisano_period();

int main() {
    //std::vector<int> factors;
    //int m;
    //std::cin >> m;
    //std::cout << pisanoPeriod(m) << std::endl;
    test_pisano_period();
    
    return 0;
}
