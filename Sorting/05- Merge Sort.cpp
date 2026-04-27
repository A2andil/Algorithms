// In The Name of Allah

// Merge Sort
//
// Problem:   Sort an array in non-decreasing order.
// Approach:  Divide and conquer. Split the array in half, recursively sort
//            each half, then merge the two sorted halves into one.
// Time:      O(n log n) in all cases
// Space:     O(n) for the merge buffer
// Stable:    Yes

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& v, int left, int mid, int right) {
    vector<int> aux;
    aux.reserve(right - left + 1);
    int i = left, j = mid + 1;
    while (i <= mid || j <= right) {
        if (j > right || (i <= mid && v[i] <= v[j])) aux.push_back(v[i++]);
        else aux.push_back(v[j++]);
    }
    for (int k = 0; k < (int)aux.size(); k++) v[left + k] = aux[k];
}

void merge_sort(vector<int>& v, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    merge_sort(v, left, mid);
    merge_sort(v, mid + 1, right);
    merge(v, left, mid, right);
}

int main() {
    vector<int> v = {38, 27, 43, 3, 9, 82, 10};
    merge_sort(v, 0, (int)v.size() - 1);
    cout << "Sorted:";
    for (int x : v) cout << " " << x;
    cout << endl;
    return 0;
}
