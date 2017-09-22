// in the name of God


#include <iostream>
#include <string>

#define d 256
#define q 101
#define ll long long
using namespace std;

void rabin_karp(string pat, string txt) {
    int M = pat.length(), N = txt.length(), i, j;
    int p = 0, t = 0, h = 1;
    for (i = 0; i < M-1; i++) h = (h * d) % q;
    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }
    for (i = 0; i <= N - M; i++) {
        if (p == t) {
            for (j = 0; j < M; j++) {
                if (txt[i+j] != pat[j])
                    break;
            }
            if (j == M) cout << "Pattern found at index " <<  i << endl;
        }
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            if (t < 0) t = (t + q);
        }
    }
}
int main() {
    return 0;
}
