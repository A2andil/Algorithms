// In The Name of Allah

// Ternary Search
//
// Problem:   Find a target in a sorted array, OR find the extremum of a unimodal
//            function. This file demonstrates both:
//              (a) discrete ternary search on a sorted array (returns index or -1)
//              (b) continuous ternary search to maximize a unimodal f over [lo, hi]
// Approach:  Split the range into thirds and discard one third per iteration.
// Time:      O(log_3 n)
// Space:     O(1)

#include <iostream>
#include <vector>
using namespace std;

int ternary_search(const vector<int>& a, int target) {
    int l = 0, r = (int)a.size() - 1;
    while (l <= r) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        if (a[m1] == target) return m1;
        if (a[m2] == target) return m2;
        if (target < a[m1]) r = m1 - 1;
        else if (target > a[m2]) l = m2 + 1;
        else { l = m1 + 1; r = m2 - 1; }
    }
    return -1;
}

double f(double x) {
    // unimodal example: -(x-3)^2 + 9, maximum at x = 3
    return -(x - 3) * (x - 3) + 9;
}

double ternary_search_max(double lo, double hi) {
    for (int i = 0; i < 200; i++) {
        double m1 = lo + (hi - lo) / 3.0;
        double m2 = hi - (hi - lo) / 3.0;
        if (f(m1) < f(m2)) lo = m1;
        else hi = m2;
    }
    return (lo + hi) / 2.0;
}

int main() {
    vector<int> a = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    cout << "index of 11: " << ternary_search(a, 11) << endl;
    cout << "index of 4:  " << ternary_search(a, 4) << endl;

    double x = ternary_search_max(-10, 10);
    cout << "max of f near x = " << x << ", f(x) = " << f(x) << endl;
    return 0;
}
