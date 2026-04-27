// In The Name of Allah

// Z-Algorithm
//
// Problem:   For string s, compute z[i] = length of the longest substring
//            starting at i that matches a prefix of s. Used for pattern
//            matching: build s = pattern + "$" + text, and any z[i] equal to
//            |pattern| is a match.
// Approach:  Maintain a window [l, r] which is the rightmost prefix-match
//            seen so far; reuse already-computed z values inside this window
//            and extend explicitly when needed.
// Time:      O(|s|)
// Space:     O(|s|)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> z_function(const string& s) {
    int n = (int)s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > r) { l = i; r = i + z[i]; }
    }
    return z;
}

vector<int> find_all_occurrences(const string& text, const string& pattern) {
    string s = pattern + "$" + text;
    vector<int> z = z_function(s);
    int m = (int)pattern.size();
    vector<int> matches;
    for (int i = m + 1; i < (int)s.size(); i++) {
        if (z[i] == m) matches.push_back(i - m - 1);
    }
    return matches;
}

int main() {
    string text = "abxabcabcaby";
    string pattern = "abcaby";
    auto matches = find_all_occurrences(text, pattern);
    cout << "Pattern \"" << pattern << "\" found in \"" << text << "\" at:";
    for (int idx : matches) cout << " " << idx;
    cout << endl;

    string s = "aabaab";
    auto z = z_function(s);
    cout << "Z-array of \"" << s << "\":";
    for (int v : z) cout << " " << v;
    cout << endl;
    return 0;
}
