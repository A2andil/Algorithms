// In The Name of Allah

// Jump Search
//
// Problem:   Find target in a sorted array.
// Approach:  Jump forward in steps of size sqrt(n). Once we overshoot, do a
//            linear scan within the previous block.
// Time:      O(sqrt(n))
// Space:     O(1)
//
// Useful when random access is cheap but comparisons are not, or as a teaching
// stepping stone between linear and binary search.

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int jump_search(const vector<int>& a, int target) {
    int n = (int)a.size();
    if (n == 0) return -1;
    int step = max(1, (int)sqrt((double)n));
    int prev = 0;
    while (prev < n && a[min(step, n) - 1] < target) {
        prev = step;
        step += (int)sqrt((double)n);
        if (prev >= n) return -1;
    }
    for (int i = prev; i < min(step, n); i++) {
        if (a[i] == target) return i;
    }
    return -1;
}

int main() {
    vector<int> a = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29};
    cout << "index of 17: " << jump_search(a, 17) << endl;
    cout << "index of 1:  " << jump_search(a, 1) << endl;
    cout << "index of 30: " << jump_search(a, 30) << endl;
    return 0;
}
