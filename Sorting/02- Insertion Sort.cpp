// In The Name of Allah

// Insertion Sort
//
// Problem:   Sort an array in non-decreasing order.
// Approach:  For each element, swap it left until it finds its correct
//            position among the already-sorted prefix.
// Time:      O(n^2) worst case, O(n) on already-sorted input
// Space:     O(1) — sorts in place
// Stable:    Yes
//
// Excellent on small or nearly-sorted arrays. Used as the base case in many
// hybrid sorts (e.g. introsort, timsort) for n below a small threshold.

#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int>& v) {
    for (int i = 1; i < (int)v.size(); i++) {
        int key = v[i], j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

int main() {
    vector<int> v = {12, 11, 13, 5, 6};
    insertion_sort(v);
    cout << "Sorted:";
    for (int x : v) cout << " " << x;
    cout << endl;
    return 0;
}
