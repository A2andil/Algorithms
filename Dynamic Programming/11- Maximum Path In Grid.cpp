// In The Name of Allah

// Maximum Path Sum in a Grid
//
// Problem:   In an r x c grid of values, find the maximum sum of a path
//            from the top-left to the bottom-right cell, where each step
//            goes either right or down.
// Approach:  dp[i][j] = max sum of any valid path ending at (i, j).
//              dp[i][j] = grid[i][j] + max(dp[i-1][j], dp[i][j-1])
//            with dp[0][0] = grid[0][0] and dp[-1][*]/dp[*][-1] treated as
//            -infinity (or handled via boundary checks).
// Time:      O(r * c)
// Space:     O(r * c), reducible to O(c) with a 1-D rolling row.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_path(const vector<vector<int>>& grid) {
    int r = (int)grid.size();
    if (r == 0) return 0;
    int c = (int)grid[0].size();
    vector<vector<int>> dp(r, vector<int>(c, 0));
    dp[0][0] = grid[0][0];
    for (int j = 1; j < c; j++) dp[0][j] = dp[0][j - 1] + grid[0][j];
    for (int i = 1; i < r; i++) dp[i][0] = dp[i - 1][0] + grid[i][0];
    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            dp[i][j] = grid[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[r - 1][c - 1];
}

int main() {
    vector<vector<int>> grid = {
        {3, 7, 9, 2, 7},
        {9, 8, 3, 5, 5},
        {1, 7, 9, 8, 5},
        {3, 8, 6, 4, 9},
        {6, 3, 9, 7, 8}
    };
    cout << "Max path sum: " << max_path(grid) << endl;
    return 0;
}
