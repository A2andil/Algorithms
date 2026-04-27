// In The Name of Allah

// Bubble Sort
//
// Problem:   Sort an array in non-decreasing order.
// Approach:  Repeatedly pass over the array swapping adjacent out-of-order
//            pairs. After pass k, the k largest elements are in place at
//            the end. Early-exit if a pass made no swaps (already sorted).
// Time:      O(n^2) worst, O(n) best (already sorted with early-exit)
// Space:     O(1)
// Stable:    Yes
//
// Almost always strictly worse than insertion sort. Educational value only.

#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int>& v) {
    int n = (int)v.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    vector<int> v = {64, 34, 25, 12, 22, 11, 90};
    bubble_sort(v);
    cout << "Sorted:";
    for (int x : v) cout << " " << x;
    cout << endl;
    return 0;
}
