// In The Name of Allah

// Longest Increasing Subsequence
//
// Problem:   Given an array, find the length of the longest strictly
//            increasing subsequence (not necessarily contiguous).
// Approach:  Two implementations:
//              - lis_n2:    classical DP, dp[i] = longest LIS ending at i.
//                            O(n^2), simple, also lets you reconstruct.
//              - lis_nlogn: maintain a "tails" array via patience sorting.
//                            tails[k] = smallest possible tail of any IS
//                            of length k+1 seen so far. Binary search to
//                            place each element. Length = |tails|.
// Time:      O(n^2)  /  O(n log n)
// Space:     O(n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lis_n2(const vector<int>& a) {
    int n = (int)a.size();
    if (n == 0) return 0;
    vector<int> dp(n, 1);
    int best = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
        }
        best = max(best, dp[i]);
    }
    return best;
}

int lis_nlogn(const vector<int>& a) {
    vector<int> tails;
    for (int x : a) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    return (int)tails.size();
}

int main() {
    vector<int> a = {10, 22, 9, 33, 21, 50, 41, 60, 70};
    cout << "LIS (n^2)    = " << lis_n2(a) << endl;
    cout << "LIS (n logn) = " << lis_nlogn(a) << endl;

    vector<int> b = {3, 10, 2, 1, 20};
    cout << "LIS (n logn) of {3,10,2,1,20} = " << lis_nlogn(b) << endl;
    return 0;
}
