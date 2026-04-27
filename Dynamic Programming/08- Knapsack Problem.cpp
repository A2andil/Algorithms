// In The Name of Allah

// 0/1 Knapsack
//
// Problem:   Given n items with weights wt[] and values val[] and a knapsack
//            of capacity W, choose a subset of items to maximize total value
//            without exceeding W. Each item is either taken once or not at all.
// Approach:  dp[i][w] = max value using the first i items with capacity w.
//              dp[i][w] = dp[i-1][w]                                  (skip)
//                       = max(dp[i-1][w], val[i-1] + dp[i-1][w - wt[i-1]])
//                                                  if wt[i-1] <= w  (take)
// Time:      O(n * W)
// Space:     O(n * W), reducible to O(W) with a 1-D rolling array.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int W, const vector<int>& wt, const vector<int>& val) {
    int n = (int)wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i - 1][w];
            if (wt[i - 1] <= w) {
                dp[i][w] = max(dp[i][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            }
        }
    }
    return dp[n][W];
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt  = {10, 20, 30};
    int W = 50;
    cout << "Best value with capacity " << W << ": " << knapsack(W, wt, val) << endl;
    return 0;
}
