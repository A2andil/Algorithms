// in the name of God

#include <iostream>
#include <vector>

using namespace std;

vector<int> v, aux;
void merge_sort(int left, int right) {
        if (left == right) {
                return;
        }
        int md = (left + right) / 2;
        merge_sort(left, md);
        merge_sort(md + 1, right);
        aux.clear();
        int i = left, j = md + 1;
        while (i <= md || j <= right) {
                if (j > right || (i <= md && v[i] < v[j])) {
                        aux.push_back(v[i]);
                        i += 1;
                }
                else {
                        aux.push_back(v[j]);
                        j += 1;
                }
        }
        for (int i = left; i <= right; i += 1) {
                v[i] = aux[i - left];
        }
}

int main() {
    return 0;
}
