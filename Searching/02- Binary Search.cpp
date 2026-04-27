// In The Name of Allah

// Binary Search
//
// Problem:   Find the index of a target value in a SORTED array. Return -1
//            if not present.
// Approach:  Compare target to the middle; recurse/iterate on the half that
//            could contain it.
// Time:      O(log n)
// Space:     O(log n) recursion stack (or O(1) for the iterative version)
//
// Pre-condition: the array must be sorted in non-decreasing order.

#include <iostream>
#include <vector>
using namespace std;

int binary_search_rec(const vector<int>& a, int target, int left, int right) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (a[mid] == target) return mid;
    if (a[mid] > target) return binary_search_rec(a, target, left, mid - 1);
    return binary_search_rec(a, target, mid + 1, right);
}

int binary_search_iter(const vector<int>& a, int target) {
    int left = 0, right = (int)a.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == target) return mid;
        if (a[mid] > target) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

int main() {
    vector<int> a = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    cout << "rec  index of 15: " << binary_search_rec(a, 15, 0, (int)a.size() - 1) << endl;
    cout << "iter index of 15: " << binary_search_iter(a, 15) << endl;
    cout << "iter index of 4:  " << binary_search_iter(a, 4) << endl;
    return 0;
}
