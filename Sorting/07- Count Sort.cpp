// in the name of God

#include <iostream>
#include <vector>

#define ll long long
#define uint unsigned int
using namespace std;

vector<int> list;

void counting_sort() {
    int mx = 0;
    for (uint i = 0; i < list.size(); i++) {
        mx = max(mx, list[i]);
    }
    int count[mx + 1], sorted_list[list.size()];

    for (int i = 0; i <= mx; i++)
        count[i] = 0;
    for (uint j = 0; j < list.size(); j++)
        count[list[j]] += 1;

    for (int i = 1; i <= mx; i++)
        count[i] = count[i] + count[i - 1];

    for (uint j = 0; j < list.size(); j++) {
        sorted_list[count[list[j]] - 1] = list[j];
        count[list[j]] -= 1;
    }
}

int main() {
    return 0;
}
