// In The Name of Allah

// Iterative Factorial
//
// Problem:   Compute n! = 1 * 2 * 3 * ... * n.
// Approach:  Multiply 1..n in a loop.
// Time:      O(n)
// Space:     O(1)
//
// Note: 20! is the largest factorial that fits in a signed 64-bit integer.

#include <iostream>
using namespace std;

long long fact(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++) res *= i;
    return res;
}

int main() {
    for (int n : {0, 1, 5, 10, 20}) {
        cout << n << "! = " << fact(n) << endl;
    }
    return 0;
}
