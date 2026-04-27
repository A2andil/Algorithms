// In The Name of Allah

// Palindrome Partitioning — minimum cuts
//
// Problem:   Cut a string s into pieces such that every piece is a palindrome.
//            Return the minimum number of cuts needed.
// Approach:  Two DPs:
//              1. is_pal[i][j]: precompute whether s[i..j] is a palindrome.
//                 is_pal[i][j] = (s[i] == s[j]) && (j - i < 2 || is_pal[i+1][j-1])
//              2. cuts[i]: min cuts needed for prefix s[0..i].
//                 cuts[i] = 0 if s[0..i] is itself a palindrome, else
//                 cuts[i] = 1 + min over j in [1..i] of cuts[j-1] when s[j..i] is a palindrome.
// Time:      O(n^2)
// Space:     O(n^2)

#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int min_cuts(const string& s) {
    int n = (int)s.size();
    if (n <= 1) return 0;
    vector<vector<bool>> is_pal(n, vector<bool>(n, false));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (s[i] == s[j] && (j - i < 2 || is_pal[i + 1][j - 1])) {
                is_pal[i][j] = true;
            }
        }
    }
    vector<int> cuts(n, 0);
    for (int i = 0; i < n; i++) {
        if (is_pal[0][i]) { cuts[i] = 0; continue; }
        cuts[i] = INT_MAX;
        for (int j = 1; j <= i; j++) {
            if (is_pal[j][i]) cuts[i] = min(cuts[i], cuts[j - 1] + 1);
        }
    }
    return cuts[n - 1];
}

int main() {
    cout << "min cuts in \"aab\" = " << min_cuts("aab") << endl;
    cout << "min cuts in \"ababbbabbababa\" = " << min_cuts("ababbbabbababa") << endl;
    cout << "min cuts in \"abcde\" = " << min_cuts("abcde") << endl;
    cout << "min cuts in \"racecar\" = " << min_cuts("racecar") << endl;
    return 0;
}
