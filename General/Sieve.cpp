// In The Name of Allah

// Sieve of Eratosthenes
//
// Problem:   Find every prime up to n.
// Approach:  Mark multiples of each prime starting from p*p.
// Time:      O(n log log n)
// Space:     O(n)
//
// For finding primes in a high range like [10^11, 10^11 + 10^6] without
// allocating O(R) memory, use Segmented Sieve.cpp.

#include <iostream>
#include <vector>
using namespace std;

vector<int> sieve(int n) {
    vector<char> is_prime(n + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int p = 2; (long long)p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) is_prime[i] = 0;
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; i++) if (is_prime[i]) primes.push_back(i);
    return primes;
}

int main() {
    int n = 50;
    auto primes = sieve(n);
    cout << "Primes up to " << n << ":";
    for (int p : primes) cout << " " << p;
    cout << endl;
    cout << "Count of primes up to 1000: " << sieve(1000).size() << endl;
    return 0;
}
