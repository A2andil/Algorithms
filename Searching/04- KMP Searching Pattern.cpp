// In The Name of Allah

// Knuth-Morris-Pratt Pattern Matching
//
// Problem:   Find all occurrences of a pattern P in a text T.
// Approach:  Precompute lps[i] = length of the longest proper prefix of
//            P[0..i] that is also a suffix. While scanning T, on a mismatch
//            jump back using lps instead of restarting — never re-compares
//            characters of T.
// Time:      O(n + m) where n = |T|, m = |P|
// Space:     O(m)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> compute_lps(const string& pat) {
    int m = (int)pat.size();
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) {
            lps[i++] = ++len;
        } else if (len != 0) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}

vector<int> kmp(const string& text, const string& pat) {
    vector<int> matches;
    int n = (int)text.size(), m = (int)pat.size();
    if (m == 0) return matches;
    vector<int> lps = compute_lps(pat);
    int i = 0, j = 0;
    while (i < n) {
        if (pat[j] == text[i]) { i++; j++; }
        if (j == m) {
            matches.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pat[j] != text[i]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return matches;
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";
    auto matches = kmp(text, pat);
    cout << "Pattern \"" << pat << "\" found in \"" << text << "\" at:";
    for (int idx : matches) cout << " " << idx;
    cout << endl;

    text = "aaaaaa";
    pat = "aa";
    matches = kmp(text, pat);
    cout << "Pattern \"" << pat << "\" found in \"" << text << "\" at:";
    for (int idx : matches) cout << " " << idx;
    cout << endl;
    return 0;
}
