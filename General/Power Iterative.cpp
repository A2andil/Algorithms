// In The Name of Allah

// Power (naive iterative)
//
// Problem:   Compute base^exp.
// Approach:  Multiply by base exp times in a loop.
// Time:      O(exp)
// Space:     O(1)
//
// For exp larger than ~30, prefer the O(log exp) version in Power.cpp or
// Modular Exponentiation.cpp.

#include <iostream>
using namespace std;

long long power(long long base, int exp) {
    if (exp == 0) return 1;
    long long res = 1;
    for (int i = 1; i <= exp; i++) res *= base;
    return res;
}

int main() {
    cout << "2^10 = " << power(2, 10) << endl;
    cout << "3^5  = " << power(3, 5) << endl;
    cout << "7^0  = " << power(7, 0) << endl;
    return 0;
}
