// in the name of God

#include <iostream>
#include <vector>

#define ll long long
using namespace std;

vector<int> list;

int partion(int lw, int hi) {
        int x = list[hi], i = lw - 1;
        for (int j = lw; j < hi - 1; j += 1) {
                if (list[j] <= x) {
                        i += 1;
                        swap(list[j], list[i]);
                }
        }
        if (list[i + 1] > list[hi]) {
                swap(list[hi], list[i + 1]);
                return i + 1;
        }
        return hi;
}

void quick_sort(int lw, int hi) {
        if (lw < hi) {
                int idx = partion(lw, hi);
                quick_sort(lw, idx - 1);
                quick_sort(idx + 1, hi);
        }
}

int main() {
        return 0;
}
