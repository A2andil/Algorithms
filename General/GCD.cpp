// In The Name of Allah

// Greatest Common Divisor (Euclidean algorithm)
//
// Problem:   Compute gcd(a, b), the largest positive integer that divides
//            both a and b.
// Approach:  gcd(a, b) = gcd(b, a mod b), with gcd(a, 0) = a.
// Time:      O(log min(a, b))
// Space:     O(log min(a, b)) recursion stack

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cout << "gcd(49, 10) = " << gcd(49, 10) << endl;
    cout << "gcd(48, 18) = " << gcd(48, 18) << endl;
    cout << "gcd(17, 0)  = " << gcd(17, 0) << endl;
    return 0;
}
