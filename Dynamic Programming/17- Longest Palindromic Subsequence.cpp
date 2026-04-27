// In The Name of Allah

// Longest Palindromic Subsequence
//
// Problem:   Given a string s, find the length of the longest subsequence
//            (not contiguous) of s that is a palindrome.
// Approach:  dp[i][j] = LPS length of s[i..j].
//              if s[i] == s[j]:  dp[i][j] = dp[i+1][j-1] + 2
//              else:             dp[i][j] = max(dp[i+1][j], dp[i][j-1])
// Time:      O(n^2)
// Space:     O(n^2)
//
// Equivalent formulation: LPS(s) == LCS(s, reverse(s)).

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int lps_length(const string& s) {
    int n = (int)s.size();
    if (n == 0) return 0;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) dp[i][j] = (len == 2 ? 2 : dp[i + 1][j - 1] + 2);
            else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][n - 1];
}

int main() {
    cout << "LPS of \"bbbab\"   = " << lps_length("bbbab") << endl;
    cout << "LPS of \"agbdba\"  = " << lps_length("agbdba") << endl;
    cout << "LPS of \"character\" = " << lps_length("character") << endl;
    return 0;
}
