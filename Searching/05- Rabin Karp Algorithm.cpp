// In The Name of Allah

// Rabin-Karp Pattern Matching
//
// Problem:   Find all occurrences of a pattern P in a text T.
// Approach:  Compute a rolling polynomial hash of every length-|P| window in
//            T and compare to hash(P). When hashes match, verify character by
//            character (handles hash collisions). With a small prime modulus
//            this is occasionally O(n*m) worst case; with a large random
//            modulus it's expected O(n + m).
// Time:      O(n + m) average, O(n*m) worst
// Space:     O(1)
//
// Sweet spot: matching many patterns of the same length against one text
// (precompute the rolling hash once, hash every pattern, compare).

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const long long BASE = 256;
const long long MOD  = 1000000007LL;

vector<int> rabin_karp(const string& text, const string& pat) {
    vector<int> matches;
    int n = (int)text.size(), m = (int)pat.size();
    if (m == 0 || m > n) return matches;

    long long h = 1;
    for (int i = 0; i < m - 1; i++) h = (h * BASE) % MOD;

    long long p = 0, t = 0;
    for (int i = 0; i < m; i++) {
        p = (BASE * p + (unsigned char)pat[i]) % MOD;
        t = (BASE * t + (unsigned char)text[i]) % MOD;
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            int j = 0;
            while (j < m && text[i + j] == pat[j]) j++;
            if (j == m) matches.push_back(i);
        }
        if (i < n - m) {
            t = (BASE * (t - (unsigned char)text[i] * h) + (unsigned char)text[i + m]) % MOD;
            if (t < 0) t += MOD;
        }
    }
    return matches;
}

int main() {
    string text = "GEEKS FOR GEEKS";
    string pat = "GEEK";
    auto matches = rabin_karp(text, pat);
    cout << "Pattern \"" << pat << "\" found in \"" << text << "\" at:";
    for (int idx : matches) cout << " " << idx;
    cout << endl;

    text = "ABCABCDABCABCAB";
    pat = "ABCAB";
    matches = rabin_karp(text, pat);
    cout << "Pattern \"" << pat << "\" found in \"" << text << "\" at:";
    for (int idx : matches) cout << " " << idx;
    cout << endl;
    return 0;
}
