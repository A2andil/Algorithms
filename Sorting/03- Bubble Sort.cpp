// in the name of God

#include <iostream>
#include <vector>

using namespace std;

vector<int> bubble_sort(vector<int> v) {
    bool is_sorted;
    do {
        is_sorted = true;
        for (int i = 1; i < (int)v.size(); i += 1) {
            if (v[i] < v[i - 1]) {
                is_sorted = false;
                swap(v[i], v[i - 1]);
            }
        }
    } while (!is_sorted);
    return v;
}

int main() {
    return 0;
}
