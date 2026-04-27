// In The Name of Allah

// Segmented Sieve of Eratosthenes
//
// Problem:   List all primes in a range [L, R] where R can be up to ~10^12,
//            without allocating O(R) memory.
// Approach:  Sieve primes up to sqrt(R) the normal way. For the segment [L, R],
//            for each small prime p mark its multiples as composite, working in
//            a length-(R-L+1) bool array.
// Time:      O((R - L + sqrt(R)) log log R)
// Space:     O(R - L + sqrt(R))

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> segmented_sieve(long long L, long long R) {
    long long lim = (long long)sqrt((double)R) + 1;
    vector<char> mark(lim + 1, 0);
    vector<long long> small_primes;
    for (long long i = 2; i <= lim; i++) {
        if (!mark[i]) {
            small_primes.push_back(i);
            for (long long j = i * i; j <= lim; j += i) mark[j] = 1;
        }
    }

    vector<char> is_comp(R - L + 1, 0);
    for (long long p : small_primes) {
        long long start = max(p * p, ((L + p - 1) / p) * p);
        for (long long j = start; j <= R; j += p) is_comp[j - L] = 1;
    }

    vector<long long> result;
    for (long long i = max(L, 2LL); i <= R; i++) {
        if (!is_comp[i - L]) result.push_back(i);
    }
    return result;
}

int main() {
    long long L = 100, R = 200;
    auto primes = segmented_sieve(L, R);
    cout << "Primes in [" << L << ", " << R << "]:";
    for (auto p : primes) cout << " " << p;
    cout << endl;

    L = 1000000000LL; R = 1000000100LL;
    primes = segmented_sieve(L, R);
    cout << "Primes in [" << L << ", " << R << "]:";
    for (auto p : primes) cout << " " << p;
    cout << endl;
    return 0;
}
