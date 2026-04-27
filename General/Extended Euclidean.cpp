// In The Name of Allah

// Extended Euclidean Algorithm
//
// Problem:   Find integers x, y such that a*x + b*y = gcd(a, b) (Bezout identity).
// Approach:  Recurse on gcd(b, a%b); back-substitute to recover (x, y).
// Time:      O(log min(a, b))
// Space:     O(log min(a, b)) recursion stack

#include <iostream>
using namespace std;

long long ext_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long g = ext_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int main() {
    long long a = 30, b = 18, x, y;
    long long g = ext_gcd(a, b, x, y);
    cout << "gcd(" << a << ", " << b << ") = " << g << endl;
    cout << "x = " << x << ", y = " << y << endl;
    cout << "Check: " << a << "*" << x << " + " << b << "*" << y << " = " << a * x + b * y << endl;
    return 0;
}
