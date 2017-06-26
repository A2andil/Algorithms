// in the name of God

#include <iostream>
#include <set>
#include <algorithm>

#define ll long long
using namespace std;

vector<int> list;

int shell_sort() {
    int n = list.size(), gap = n / 2;
    while (gap > 0) {
        for (int i = gap; i < n; i += 1) {
            for (int j = i; j >= gap && list[j - gap] > list[j]; j -= gap)
                swap(list[j], list[j - gap]);
        }
        gap /= 2;
    }
}

int main() {
    return 0;
}
