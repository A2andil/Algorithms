// In The Name of Allah

// Fibonacci (recursive, no memoization)
//
// Problem:   Compute the n-th Fibonacci number.
// Approach:  Plain double-recurrence fib(n) = fib(n-1) + fib(n-2).
// Time:      O(2^n)  -- exponential, only useful for tiny n
// Space:     O(n) recursion stack
//
// Don't use this for n > 35 or so. See Fibonacci Iterative.cpp for O(n) and
// Dynamic Programming/01- Fibonacci.cpp for the memoized version.

#include <iostream>
using namespace std;

long long fib(int n) {
    if (n == 0 || n == 1) return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    for (int n : {0, 1, 5, 10, 20, 30}) {
        cout << "F(" << n << ") = " << fib(n) << endl;
    }
    return 0;
}
