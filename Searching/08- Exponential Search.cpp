// In The Name of Allah

// Exponential Search (a.k.a. Galloping / Doubling Search)
//
// Problem:   Find target in a sorted array, especially when the array is
//            unbounded or the target is likely near the front.
// Approach:  Double an index until a[i] >= target, then binary search the
//            range [i/2, min(i, n-1)].
// Time:      O(log n)
// Space:     O(1)

#include <iostream>
#include <vector>
using namespace std;

int binary_search_range(const vector<int>& a, int l, int r, int target) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] == target) return m;
        if (a[m] < target) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int exponential_search(const vector<int>& a, int target) {
    int n = (int)a.size();
    if (n == 0) return -1;
    if (a[0] == target) return 0;
    int i = 1;
    while (i < n && a[i] < target) i *= 2;
    return binary_search_range(a, i / 2, min(i, n - 1), target);
}

int main() {
    vector<int> a = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29};
    cout << "index of 1:  " << exponential_search(a, 1) << endl;
    cout << "index of 19: " << exponential_search(a, 19) << endl;
    cout << "index of 30: " << exponential_search(a, 30) << endl;
    return 0;
}
