// In The Name of Allah

// Power (naive recursive)
//
// Problem:   Compute base^exp.
// Approach:  base^exp = base * base^(exp-1), base case base^0 = 1.
// Time:      O(exp)
// Space:     O(exp) recursion stack
//
// Useful for teaching recursion only — for any real workload prefer the
// O(log exp) version in Power.cpp.

#include <iostream>
using namespace std;

long long power(long long base, int exp) {
    if (exp == 0) return 1;
    return base * power(base, exp - 1);
}

int main() {
    cout << "2^10 = " << power(2, 10) << endl;
    cout << "3^5  = " << power(3, 5) << endl;
    cout << "7^0  = " << power(7, 0) << endl;
    return 0;
}
