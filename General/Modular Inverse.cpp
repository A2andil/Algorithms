// In The Name of Allah

// Modular Inverse
//
// Problem:   Find x in [0, m) such that (a * x) mod m == 1, when gcd(a, m) == 1.
// Approach:  Two methods:
//              (1) Fermat's little theorem (m prime): a^(m-2) mod m via fast power.
//              (2) Extended Euclidean: works for any m coprime with a.
// Time:      O(log m)
// Space:     O(1) for Fermat, O(log m) stack for Euclidean

#include <iostream>
using namespace std;

long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1 % mod;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

long long inv_fermat(long long a, long long p) {
    return mod_pow(a, p - 2, p);
}

long long ext_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    long long x1, y1;
    long long g = ext_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

long long inv_extgcd(long long a, long long m) {
    long long x, y;
    long long g = ext_gcd(a, m, x, y);
    if (g != 1) return -1; // inverse does not exist
    return ((x % m) + m) % m;
}

int main() {
    long long a = 3, p = 11;
    cout << "Inverse of " << a << " mod " << p << " (Fermat) = " << inv_fermat(a, p) << endl;
    cout << "Inverse of " << a << " mod " << p << " (ExtGCD) = " << inv_extgcd(a, p) << endl;

    long long a2 = 7, m = 26;
    cout << "Inverse of " << a2 << " mod " << m << " (ExtGCD) = " << inv_extgcd(a2, m) << endl;
    return 0;
}
