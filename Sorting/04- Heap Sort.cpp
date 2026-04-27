// In The Name of Allah

// Heap Sort
//
// Problem:   Sort an array in non-decreasing order.
// Approach:  Build a max-heap in place, then repeatedly swap the root
//            (largest) with the last element of the heap and sift down.
//            After n-1 extractions the array is sorted.
// Time:      O(n log n) in all cases
// Space:     O(1) — sorts in place
// Stable:    No

#include <iostream>
#include <vector>
using namespace std;

void sift_down(vector<int>& v, int n, int i) {
    while (true) {
        int largest = i, l = 2 * i + 1, r = 2 * i + 2;
        if (l < n && v[l] > v[largest]) largest = l;
        if (r < n && v[r] > v[largest]) largest = r;
        if (largest == i) break;
        swap(v[i], v[largest]);
        i = largest;
    }
}

void heap_sort(vector<int>& v) {
    int n = (int)v.size();
    for (int i = n / 2 - 1; i >= 0; i--) sift_down(v, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(v[0], v[i]);
        sift_down(v, i, 0);
    }
}

int main() {
    vector<int> v = {12, 11, 13, 5, 6, 7, 1, 9};
    heap_sort(v);
    cout << "Sorted:";
    for (int x : v) cout << " " << x;
    cout << endl;
    return 0;
}
