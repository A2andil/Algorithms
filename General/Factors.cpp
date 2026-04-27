// In The Name of Allah

// Factors of n
//
// Problem:   List every positive integer that divides n.
// Approach:  Iterate i from 1 to sqrt(n). When i divides n, both i and n/i
//            are factors (count i only once when n is a perfect square).
// Time:      O(sqrt(n))
// Space:     O(d(n)) where d(n) = number of divisors

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> factors(int n) {
    vector<int> div;
    for (int i = 1; (long long)i * i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (i != n / i) div.push_back(n / i);
        }
    }
    sort(div.begin(), div.end());
    return div;
}

int main() {
    for (int n : {1, 12, 36, 100, 97}) {
        auto f = factors(n);
        cout << "factors of " << n << ":";
        for (int d : f) cout << " " << d;
        cout << endl;
    }
    return 0;
}
