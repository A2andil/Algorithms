// in the name of God

#include <iostream>
#include <vector>

#define ll long long
using namespace std;

vector<double> list, sorted_list;

void insertion_sort(vector<double> &v) {
        for (int i = 1; i < v.size(); i++) {
                int idx = i;
                for (int j = i - 1; j >= 0; j--) {
                        if (idx > 0 && v[idx] < v[j]) {
                                swap(v[idx], v[j]);
                                idx -= 1;
                        }
                        else break;
                }
        }
}

void bucket_sort() {
        vector<vector<double>> B(list.size() + 1);
        for (int i = 0; i < list.size(); i++) {
                int idx = list.size() * list[i];
                B[idx].push_back(list[i]);
        }
        for (int i = 0; i < list.size() + 1; i++) {
                insertion_sort(B[i]);
                for (int j = 0; j < B[i].size(); j++) {
                        sorted_list.push_back(B[i][j]);
                }
        }
}

int main()  {
    return 0;
}
