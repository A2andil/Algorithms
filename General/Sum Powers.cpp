// In The Name of Allah

// Sum of Powers
//
// Problem:   Compute S(a, n) = a^1 + a^2 + a^3 + ... + a^n.
// Approach:  Divide and conquer using the identity
//              S(a, 2k)   = S(a, k) * (1 + a^k)
//              S(a, 2k+1) = S(a, 2k) + a^(2k+1)
//            Combined with fast exponentiation for the a^k term.
// Time:      O(log n)
// Space:     O(log n) recursion stack

#include <iostream>
using namespace std;

long long fast_pow(long long a, int n) {
    if (n == 0) return 1;
    long long h = fast_pow(a, n / 2);
    return (n % 2) ? h * h * a : h * h;
}

long long sum_powers(long long a, int n) {
    if (n == 0) return 0;
    if (n == 1) return a;
    long long half = sum_powers(a, n / 2);
    long long s_even = half * (1 + fast_pow(a, n / 2));
    if (n % 2 == 0) return s_even;
    return s_even + fast_pow(a, n);
}

int main() {
    // 2^1 + 2^2 + 2^3 + 2^4 = 2 + 4 + 8 + 16 = 30
    cout << "S(2, 4) = " << sum_powers(2, 4) << " (expect 30)" << endl;
    // 5^1 + ... + 5^6 = 5 + 25 + 125 + 625 + 3125 + 15625 = 19530
    cout << "S(5, 6) = " << sum_powers(5, 6) << " (expect 19530)" << endl;
    cout << "S(3, 5) = " << sum_powers(3, 5) << " (expect 363)" << endl;
    return 0;
}
