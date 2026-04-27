// In The Name of Allah

// Catalan Numbers
//
// Problem:   Compute Cn = (2n choose n) / (n + 1).
//            Counts: balanced parentheses of length 2n, BST shapes with n nodes,
//            triangulations of an (n+2)-gon, monotonic paths on a grid, etc.
// Approach:  DP using the standard recurrence
//              C[0] = 1,  C[n] = sum_{i=0..n-1} C[i] * C[n-1-i]
// Time:      O(n^2)
// Space:     O(n)

#include <iostream>
#include <vector>
using namespace std;

vector<long long> catalan(int n) {
    vector<long long> c(n + 1, 0);
    c[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            c[i] += c[j] * c[i - 1 - j];
        }
    }
    return c;
}

int main() {
    int n = 12;
    auto c = catalan(n);
    cout << "First " << n + 1 << " Catalan numbers:" << endl;
    for (int i = 0; i <= n; i++) cout << "  C[" << i << "] = " << c[i] << endl;
    return 0;
}
