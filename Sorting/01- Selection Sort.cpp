// in the name of God

#include <iostream>
#include <vector>

using namespace std;

vector<int> sort_by_selection(vector<int> v) {
    vector<int> sorted;
    while (v.size()) {
        // find the minimum element
        int index_min = 0;
        for (int i = 1; i < (int)v.size(); i += 1) {
            if (v[i] < v[index_min]) {
                index_min = i;
            }
        }

        // insert it in the sorted array
        sorted.push_back(v[index_min]);

        // remove it from the original array
        v.erase(v.begin() + index_min);
    }
    return sorted;
}

int main() {
    return 0;
}
