// In The Name of Allah

// Longest Common Subsequence — length only
//
// Problem:   Given two strings, find the length of the longest subsequence
//            (not necessarily contiguous) that appears in both.
// Approach:  dp[i][j] = LCS length of X[0..i-1] and Y[0..j-1].
//              dp[i][j] = dp[i-1][j-1] + 1            if X[i-1] == Y[j-1]
//              dp[i][j] = max(dp[i-1][j], dp[i][j-1]) otherwise
// Time:      O(m * n)
// Space:     O(m * n)
//
// For the reconstructed sequence (not just its length), see file 05.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int lcs_length(const string& X, const string& Y) {
    int m = (int)X.size(), n = (int)Y.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int main() {
    string X = "AGGTAB", Y = "GXTXAYB";
    cout << "LCS length of \"" << X << "\" and \"" << Y << "\" = " << lcs_length(X, Y) << endl;
    cout << "LCS length of \"abcde\" and \"ace\"  = " << lcs_length("abcde", "ace") << endl;
    return 0;
}
