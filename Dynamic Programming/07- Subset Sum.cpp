// In The Name of Allah

// Subset Sum
//
// Problem:   Given a set of non-negative integers and a target S, decide
//            whether some subset sums to exactly S.
// Approach:  dp[i][s] = true iff some subset of the first i elements sums
//            to s. Transitions:
//              dp[i][s] = dp[i-1][s]                            (skip a[i-1])
//                       OR dp[i-1][s - a[i-1]]  if a[i-1] <= s  (take a[i-1])
//            Base: dp[i][0] = true for all i.
// Time:      O(n * S)
// Space:     O(n * S), reducible to O(S) with a 1-D rolling array.

#include <iostream>
#include <vector>
using namespace std;

bool subset_sum(const vector<int>& a, int target) {
    int n = (int)a.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    for (int i = 0; i <= n; i++) dp[i][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= target; s++) {
            dp[i][s] = dp[i - 1][s];
            if (a[i - 1] <= s) dp[i][s] = dp[i][s] || dp[i - 1][s - a[i - 1]];
        }
    }
    return dp[n][target];
}

int main() {
    vector<int> a = {3, 34, 4, 12, 5, 2};
    for (int target : {9, 30, 1, 0}) {
        cout << "subset of {3,34,4,12,5,2} summing to " << target << ": "
             << (subset_sum(a, target) ? "yes" : "no") << endl;
    }
    return 0;
}
