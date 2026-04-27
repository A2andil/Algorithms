// In The Name of Allah

// Quick Sort (Lomuto partition)
//
// Problem:   Sort an array in non-decreasing order.
// Approach:  Pick a pivot, partition the array so values < pivot are left
//            and values > pivot are right, then recurse on each side.
// Time:      O(n log n) average, O(n^2) worst (e.g. already sorted with
//            last-element pivot — randomize the pivot to avoid this).
// Space:     O(log n) recursion stack on average
// Stable:    No
//
// In practice the fastest comparison-based sort for general data, which is
// why std::sort uses an introsort variant of it.

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& v, int lo, int hi) {
    int pivot = v[hi];
    int i = lo - 1;
    for (int j = lo; j < hi; j++) {
        if (v[j] <= pivot) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[hi]);
    return i + 1;
}

void quick_sort(vector<int>& v, int lo, int hi) {
    if (lo < hi) {
        int p = partition(v, lo, hi);
        quick_sort(v, lo, p - 1);
        quick_sort(v, p + 1, hi);
    }
}

int main() {
    vector<int> v = {10, 7, 8, 9, 1, 5};
    quick_sort(v, 0, (int)v.size() - 1);
    cout << "Sorted:";
    for (int x : v) cout << " " << x;
    cout << endl;
    return 0;
}
