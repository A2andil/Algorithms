// In The Name of Allah

// Minimum Edit Distance (Levenshtein)
//
// Problem:   Find the minimum number of single-character edits (insert,
//            delete, replace) required to transform string X into Y.
// Approach:  dp[i][j] = edit distance between X[0..i-1] and Y[0..j-1].
//              dp[0][j] = j  (insert j chars), dp[i][0] = i  (delete i chars)
//              if X[i-1] == Y[j-1]: dp[i][j] = dp[i-1][j-1]
//              else dp[i][j] = 1 + min(dp[i-1][j],     // delete from X
//                                       dp[i][j-1],     // insert into X
//                                       dp[i-1][j-1])   // replace
// Time:      O(m * n)
// Space:     O(m * n)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int edit_distance(const string& X, const string& Y) {
    int m = (int)X.size(), n = (int)Y.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }
    return dp[m][n];
}

int main() {
    cout << "edit(\"sunday\", \"saturday\") = " << edit_distance("sunday", "saturday") << endl;
    cout << "edit(\"kitten\", \"sitting\") = " << edit_distance("kitten", "sitting") << endl;
    cout << "edit(\"abc\", \"abc\")        = " << edit_distance("abc", "abc") << endl;
    return 0;
}
