//in the name of God

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define ll long long
#define oo 1e9 + 7
using namespace std;

struct Node {
        int from, to, dist;
};

const int N = 1001;
int k[N], s[N];
vector<Node> v;

bool cmp(const Node &a, const Node &b) {
        return a.dist < b.dist ? true : false;
}

int find(int x) {
        while (x != k[x]) {
                x = k[x];
        }
        return x;
}

bool same(int a, int b) {
        return find(a) == find(b);
}

void Union(int a, int b) {
        a = find(a), b = find(b);
        if (s[a] < s[b]) swap(a, b);
        s[a] += s[b];
        k[b] = a;
}

void Kruskal() {
        for (int i = 1; i < N; i++)
                k[i] = i, s[i] = 1;
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < v.size(); i++) {
                if (!same(v[i].from, v[i].to)) {
                        Union(v[i].from, v[i].to);
                }
        }
}

int main() {

    return 0;
}
