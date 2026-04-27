// In The Name of Allah

// Least Common Multiple
//
// Problem:   Compute lcm(a, b), the smallest positive integer divisible by
//            both a and b.
// Approach:  lcm(a, b) = a / gcd(a, b) * b. Dividing by gcd first avoids
//            overflow that the equivalent (a * b) / gcd(a, b) would risk.
// Time:      O(log min(a, b))
// Space:     O(log min(a, b)) recursion stack

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(int a, int b) {
    return (long long)a / gcd(a, b) * b;
}

int main() {
    cout << "lcm(49, 10) = " << lcm(49, 10) << endl;
    cout << "lcm(12, 18) = " << lcm(12, 18) << endl;
    cout << "lcm(7, 5)   = " << lcm(7, 5) << endl;
    return 0;
}
