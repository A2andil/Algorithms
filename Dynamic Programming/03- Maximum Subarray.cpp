// In The Name of Allah

// Maximum Subarray Sum (Kadane's Algorithm)
//
// Problem:   In an array of integers (positive and negative), find the
//            contiguous subarray with the largest sum.
// Approach:  Track best[i] = max sum of any subarray ending at i:
//              best[i] = max(a[i], best[i-1] + a[i])
//            The answer is the maximum over all i. Constant extra space
//            since we only need the previous best.
// Time:      O(n)
// Space:     O(1)

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int max_subarray(const vector<int>& a) {
    if (a.empty()) return 0;
    int best = a[0], cur = a[0];
    for (int i = 1; i < (int)a.size(); i++) {
        cur = max(a[i], cur + a[i]);
        best = max(best, cur);
    }
    return best;
}

int main() {
    vector<int> a = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << "Max subarray sum: " << max_subarray(a) << " (expect 7)" << endl;

    vector<int> b = {-5, -2, -3};
    cout << "Max subarray sum: " << max_subarray(b) << " (expect -2)" << endl;

    vector<int> c = {1, 2, 3, 4, 5};
    cout << "Max subarray sum: " << max_subarray(c) << " (expect 15)" << endl;
    return 0;
}
