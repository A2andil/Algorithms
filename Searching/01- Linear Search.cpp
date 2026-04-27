// In The Name of Allah

// Linear Search
//
// Problem:   Find the index of the first occurrence of a target value in
//            an array. Return -1 if not present.
// Approach:  Scan left to right, comparing each element to the target.
// Time:      O(n)
// Space:     O(1)
//
// Works on unsorted data. The right choice when n is small or the array is
// not sorted; otherwise prefer Binary/Jump/Exponential search.

#include <iostream>
#include <vector>
using namespace std;

int linear_search(const vector<int>& a, int target) {
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] == target) return i;
    }
    return -1;
}

int main() {
    vector<int> a = {1, 2, 5, 3, 7, 8, 9, 4, 2, 1};
    cout << "index of 7:  " << linear_search(a, 7) << endl;
    cout << "index of 2:  " << linear_search(a, 2) << " (first occurrence)" << endl;
    cout << "index of 99: " << linear_search(a, 99) << endl;
    return 0;
}
