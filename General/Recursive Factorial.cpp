// In The Name of Allah

// Recursive Factorial
//
// Problem:   Compute n! = 1 * 2 * 3 * ... * n.
// Approach:  fact(n) = n * fact(n-1), base case fact(0) = fact(1) = 1.
// Time:      O(n)
// Space:     O(n) recursion stack
//
// Prefer the iterative version in production: same time, O(1) space.

#include <iostream>
using namespace std;

long long fact(int n) {
    if (n == 0 || n == 1) return 1;
    return (long long)n * fact(n - 1);
}

int main() {
    for (int n : {0, 1, 5, 10, 20}) {
        cout << n << "! = " << fact(n) << endl;
    }
    return 0;
}
