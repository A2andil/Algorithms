// In The Name of Allah

// Fibonacci (Bottom-up DP)
//
// Problem:   Compute the n-th Fibonacci number, F(0)=0, F(1)=1,
//            F(n) = F(n-1) + F(n-2).
// Approach:  Tabulate F(0)..F(n) iteratively. Compare against the naive
//            recursion (O(2^n)) to see why memoization matters.
// Time:      O(n)
// Space:     O(n) for the table; can be reduced to O(1) (see
//            General/Fibonacci Iterative.cpp).

#include <iostream>
#include <vector>
using namespace std;

long long fibonacci(int n) {
    if (n < 2) return n;
    vector<long long> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) fib[i] = fib[i - 1] + fib[i - 2];
    return fib[n];
}

int main() {
    for (int n : {0, 1, 5, 10, 20, 50}) {
        cout << "F(" << n << ") = " << fibonacci(n) << endl;
    }
    return 0;
}
