// In The Name of Allah

// Disjoint Set Union (Union-Find) with path compression and union by rank
//
// Problem:   Maintain a partition of {0, ..., n-1} under two operations:
//              find(x): return the representative of x's set
//              unite(x, y): merge the sets containing x and y
// Approach:  Each set is a tree; parent[x] points toward the root. Path
//            compression flattens the tree on every find. Union-by-rank
//            attaches the shallower tree under the deeper one.
// Time:      O(alpha(n)) amortized per operation (effectively O(1))
// Space:     O(n)
//
// Standalone DSU is the right primitive for Kruskal's MST, offline connectivity
// queries, Kruskal-on-trees, and many incremental-merge problems.

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

struct DSU {
    vector<int> parent, rank_;
    int components;

    DSU(int n) : parent(n), rank_(n, 0), components(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]]; // path compression (halving)
            x = parent[x];
        }
        return x;
    }

    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false;
        if (rank_[rx] < rank_[ry]) swap(rx, ry);
        parent[ry] = rx;
        if (rank_[rx] == rank_[ry]) rank_[rx]++;
        components--;
        return true;
    }

    bool same(int x, int y) { return find(x) == find(y); }
};

int main() {
    DSU d(6);
    d.unite(0, 1);
    d.unite(2, 3);
    d.unite(1, 3);
    cout << "0 and 3 connected? " << (d.same(0, 3) ? "yes" : "no") << endl;
    cout << "0 and 4 connected? " << (d.same(0, 4) ? "yes" : "no") << endl;
    cout << "components: " << d.components << endl;
    d.unite(4, 5);
    d.unite(0, 5);
    cout << "after more unions, components: " << d.components << endl;
    return 0;
}
