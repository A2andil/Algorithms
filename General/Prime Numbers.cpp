// In The Name of Allah

// Primality Check (trial division)
//
// Problem:   Decide whether n is prime.
// Approach:  Test divisibility by every i in [2, sqrt(n)].
// Time:      O(sqrt(n))
// Space:     O(1)
//
// For very large n (> 10^9 or so), use Miller Rabin.cpp instead.

#include <iostream>
using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    if (n < 4) return true;          // 2 and 3
    if (n % 2 == 0) return false;
    for (int i = 3; (long long)i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    for (int n : {1, 2, 3, 4, 17, 25, 97, 100, 7919}) {
        cout << n << " is " << (is_prime(n) ? "prime" : "composite") << endl;
    }
    return 0;
}
