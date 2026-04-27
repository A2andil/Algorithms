// In The Name of Allah

// Longest Common Subsequence — reconstruct the subsequence
//
// Problem:   Given two strings, return one longest subsequence that appears
//            in both (there may be multiple — this returns one).
// Approach:  Build the same dp[m+1][n+1] table as in file 04, then walk back
//            from dp[m][n] to dp[0][0]:
//              - if X[i-1] == Y[j-1], that character is in the LCS; go diagonally.
//              - else move toward the larger of dp[i-1][j] and dp[i][j-1].
// Time:      O(m * n)
// Space:     O(m * n)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string lcs(const string& X, const string& Y) {
    int m = (int)X.size(), n = (int)Y.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string ans;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            ans.push_back(X[i - 1]);
            i--; j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string X = "AGGTAB", Y = "GXTXAYB";
    cout << "LCS of \"" << X << "\" and \"" << Y << "\" = \"" << lcs(X, Y) << "\"" << endl;
    cout << "LCS of \"abcde\" and \"ace\"   = \"" << lcs("abcde", "ace") << "\"" << endl;
    return 0;
}
