// In The Name of Allah

// Modular Exponentiation
//
// Problem:   Compute (base^exp) mod m efficiently for large exp.
// Approach:  Binary (fast) exponentiation: square the base, halve the exponent.
// Time:      O(log exp)
// Space:     O(1)

#include <iostream>
using namespace std;

long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1 % mod;
    base %= mod;
    if (base < 0) base += mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    cout << "2^10 mod 1000 = " << mod_pow(2, 10, 1000) << endl;
    cout << "3^200 mod 1000000007 = " << mod_pow(3, 200, 1000000007) << endl;
    cout << "7^256 mod 13 = " << mod_pow(7, 256, 13) << endl;
    return 0;
}
