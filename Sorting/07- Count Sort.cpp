// In The Name of Allah

// Counting Sort
//
// Problem:   Sort an array of non-negative integers when the range of values
//            (k) is small relative to the count (n).
// Approach:  Count occurrences of each value, take a prefix sum to get
//            insertion positions, then write each input element into its
//            position in the output (right-to-left for stability).
// Time:      O(n + k)
// Space:     O(n + k)
// Stable:    Yes
//
// Used as the inner step of Radix Sort.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void counting_sort(vector<int>& v) {
    if (v.empty()) return;
    int mx = *max_element(v.begin(), v.end());
    int mn = *min_element(v.begin(), v.end());
    int range = mx - mn + 1;
    int n = (int)v.size();

    vector<int> count(range, 0), output(n);
    for (int x : v) count[x - mn]++;
    for (int i = 1; i < range; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[--count[v[i] - mn]] = v[i];
    }
    v = output;
}

int main() {
    vector<int> v = {4, 2, 2, 8, 3, 3, 1};
    counting_sort(v);
    cout << "Sorted:";
    for (int x : v) cout << " " << x;
    cout << endl;
    return 0;
}
