// In The Name of Allah

// Fibonacci (iterative)
//
// Problem:   Compute the n-th Fibonacci number, where F(0)=0, F(1)=1,
//            F(n) = F(n-1) + F(n-2).
// Approach:  Loop maintaining two rolling values.
// Time:      O(n)
// Space:     O(1)

#include <iostream>
using namespace std;

long long fibonacci(int n) {
    if (n < 2) return n;
    long long a = 0, b = 1, c = 0;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    for (int n : {0, 1, 2, 5, 10, 20, 50}) {
        cout << "F(" << n << ") = " << fibonacci(n) << endl;
    }
    return 0;
}
