// In The Name of Allah

// Selection Sort
//
// Problem:   Sort an array in non-decreasing order.
// Approach:  Repeatedly find the minimum of the unsorted suffix and swap it
//            into place at the front of that suffix.
// Time:      O(n^2)
// Space:     O(1) — sorts in place
// Stable:    No (swap of distant elements can reorder equal keys)

#include <iostream>
#include <vector>
using namespace std;

void selection_sort(vector<int>& v) {
    int n = (int)v.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min_idx]) min_idx = j;
        }
        if (min_idx != i) swap(v[i], v[min_idx]);
    }
}

int main() {
    vector<int> v = {64, 25, 12, 22, 11};
    selection_sort(v);
    cout << "Sorted:";
    for (int x : v) cout << " " << x;
    cout << endl;
    return 0;
}
