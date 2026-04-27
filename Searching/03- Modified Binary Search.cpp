// In The Name of Allah

// Modified Binary Search — first / last occurrence
//
// Problem:   In a SORTED array that may contain duplicates, find the index
//            of the first (or last) occurrence of a target.
// Approach:  Standard binary search with a twist: on a match, record the
//            index but keep narrowing toward the side you want.
// Time:      O(log n)
// Space:     O(1)

#include <iostream>
#include <vector>
using namespace std;

int first_occurrence(const vector<int>& a, int target) {
    int lo = 0, hi = (int)a.size() - 1, result = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target) {
            result = mid;
            hi = mid - 1; // keep searching left
        } else if (target < a[mid]) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return result;
}

int last_occurrence(const vector<int>& a, int target) {
    int lo = 0, hi = (int)a.size() - 1, result = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target) {
            result = mid;
            lo = mid + 1; // keep searching right
        } else if (target < a[mid]) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return result;
}

int main() {
    vector<int> a = {1, 2, 2, 2, 3, 4, 5, 5, 6, 7};
    cout << "first occurrence of 2: " << first_occurrence(a, 2) << endl;
    cout << "last  occurrence of 2: " << last_occurrence(a, 2) << endl;
    cout << "first occurrence of 5: " << first_occurrence(a, 5) << endl;
    cout << "last  occurrence of 5: " << last_occurrence(a, 5) << endl;
    cout << "first occurrence of 8: " << first_occurrence(a, 8) << endl;
    return 0;
}
