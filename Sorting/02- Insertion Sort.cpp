// in the name of God

#include <iostream>
#include <vector>

using namespace std;

vector<int> sort_by_insertion(vector<int> v) {
    for (int i = 1; i < (int)v.size(); i++) {
        for (int j = i; j > 0; j--) {
            if (v[j] < v[j - 1]) {
                swap(v[j], v[j - 1]);
            }
            else break;
        }
    }
    return v;
}

int main() {
    return 0;
}
