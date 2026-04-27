// In The Name of Allah

// Power (fast exponentiation, recursive)
//
// Problem:   Compute base^exp.
// Approach:  Halve the exponent each step:
//              base^exp = (base^(exp/2))^2                  if exp even
//              base^exp = (base^(exp/2))^2 * base           if exp odd
// Time:      O(log exp)
// Space:     O(log exp) recursion stack

#include <iostream>
using namespace std;

long long power(long long base, int exp) {
    if (exp == 0) return 1;
    long long half = power(base, exp / 2);
    return (exp % 2) ? half * half * base : half * half;
}

int main() {
    cout << "2^32 = " << power(2, 32) << endl;
    cout << "3^10 = " << power(3, 10) << endl;
    cout << "5^0  = " << power(5, 0) << endl;
    return 0;
}
