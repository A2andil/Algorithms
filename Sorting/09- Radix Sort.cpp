//in the name of God

#include <iostream>
#include <set>
#include <algorithm>

#define ll long long
using namespace std;

const int MAX = 10;
int list[MAX], result[MAX], cnt[10];

void copy() {
        for (int i = 0; i < MAX; i++) {
                list[i] = result[i];
        }
}

void count_sort(int idx) {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < MAX; i++) {
                int x = (list[i] / idx) % 10;
                cnt[x] += 1;
        }
        for (int i = 1; i < 10; i++) {
                cnt[i] += cnt[i - 1];
        }
        for (int j = MAX - 1; j >= 0; j--) {
                int x = (list[j] / idx) % 10;
                result[--cnt[x]] = list[j];
        }
        copy();
}

void radix_sort() {
        int mx = list[0];
        for (int i = 1; i < MAX; i++)
                mx = max(mx, list[i]);
        for (int i = 1; mx / i > 0; i *= 10)
                count_sort(i);
}

int main() {
        return 0;
}
