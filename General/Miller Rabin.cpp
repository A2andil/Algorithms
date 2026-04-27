// In The Name of Allah

// Miller-Rabin Primality Test (deterministic for 64-bit ints)
//
// Problem:   Decide whether n is prime, fast.
// Approach:  Write n-1 = d * 2^r. For each witness a, check whether a^d ≡ 1
//            or any a^(d*2^i) ≡ -1 (mod n). With the witness set
//            {2,3,5,7,11,13,17,19,23,29,31,37} the test is deterministic
//            for all n < 3.3 * 10^24, which covers every 64-bit unsigned.
// Time:      O(k log^3 n) where k = number of witnesses
// Space:     O(1)

#include <iostream>
using namespace std;

typedef unsigned long long u64;
typedef __int128 u128;

u64 mul_mod(u64 a, u64 b, u64 m) {
    return (u64)((u128)a * b % m);
}

u64 pow_mod(u64 a, u64 e, u64 m) {
    u64 r = 1 % m;
    a %= m;
    while (e) {
        if (e & 1) r = mul_mod(r, a, m);
        a = mul_mod(a, a, m);
        e >>= 1;
    }
    return r;
}

bool check_composite(u64 n, u64 a, u64 d, int r) {
    u64 x = pow_mod(a, d, n);
    if (x == 1 || x == n - 1) return false;
    for (int i = 0; i < r - 1; i++) {
        x = mul_mod(x, x, n);
        if (x == n - 1) return false;
    }
    return true;
}

bool is_prime(u64 n) {
    if (n < 2) return false;
    for (u64 p : {2ULL, 3ULL, 5ULL, 7ULL, 11ULL, 13ULL}) {
        if (n == p) return true;
        if (n % p == 0) return false;
    }
    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) { d >>= 1; r++; }
    for (u64 a : {2ULL, 3ULL, 5ULL, 7ULL, 11ULL, 13ULL, 17ULL, 19ULL, 23ULL, 29ULL, 31ULL, 37ULL}) {
        if (a >= n) continue;
        if (check_composite(n, a, d, r)) return false;
    }
    return true;
}

int main() {
    u64 tests[] = {1, 2, 17, 561, 1000000007ULL, 1000000008ULL, 9223372036854775783ULL};
    for (u64 n : tests) {
        cout << n << " is " << (is_prime(n) ? "prime" : "composite") << endl;
    }
    return 0;
}
