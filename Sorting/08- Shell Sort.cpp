// In The Name of Allah

// Shell Sort
//
// Problem:   Sort an array in non-decreasing order.
// Approach:  Generalization of insertion sort: do an insertion sort over
//            elements that are gap apart, halving gap each round. The early
//            wide-gap passes move elements long distances cheaply, leaving
//            only a "nearly sorted" pass at gap = 1.
// Time:      Depends on gap sequence. For halving: O(n^2) worst, ~O(n log^2 n) avg.
//            Better gap sequences (Sedgewick, Ciura) achieve ~O(n^{4/3}).
// Space:     O(1) — sorts in place
// Stable:    No

#include <iostream>
#include <vector>
using namespace std;

void shell_sort(vector<int>& v) {
    int n = (int)v.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = v[i], j = i;
            while (j >= gap && v[j - gap] > temp) {
                v[j] = v[j - gap];
                j -= gap;
            }
            v[j] = temp;
        }
    }
}

int main() {
    vector<int> v = {12, 34, 54, 2, 3, 23, 9, 11, 81, 7};
    shell_sort(v);
    cout << "Sorted:";
    for (int x : v) cout << " " << x;
    cout << endl;
    return 0;
}
