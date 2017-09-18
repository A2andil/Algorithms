// in the name of God

#include <iostream>
#include <set>
#include <cmath>
#include <stdio.h>

#define ll long long
using namespace std;

void pre_lps(string pat, int *lps) {
        int len = 0, i = 1;
        lps[0] = 0;
        while (i < pat.length()) {
                if (pat[i] == pat[len]) {
                        len += 1, lps[i] = len, i += 1;
                }
                else {
                        if (len != 0) len = lps[len - 1];
                        else lps[i] = 0, i += 1;
                }
        }
}

void kmp(string list, string pat) {
        int i = 0, j = 0, *lps = new int[pat.length()];
        pre_lps(pat, lps);
        while (i < list.length()) {
                if (pat[j] == list[i]) i += 1, j += 1;
                if (j == pat.length()) {
                        cout << "Found pattern at index " << i - j << endl;
                        j = lps[j - 1];
                }
                else if (i < list.length() && pat[j] != list[i]) {
                        if (j != 0) j = lps[j - 1];
                        else i += 1;
                }
        }
}

int main() {

        return 0;
}
