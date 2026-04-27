// In The Name of Allah

// Kruskal's Minimum Spanning Tree
//
// Problem:   In a connected weighted undirected graph, find a spanning tree
//            (V-1 edges connecting all V vertices) of minimum total weight.
// Approach:  Sort edges ascending by weight. Add each edge to the MST iff
//            its endpoints are in different components (use DSU to test
//            and merge). Stop after V-1 edges.
// Time:      O(E log E) for the sort, near O(E) for the union-find passes
// Space:     O(V + E)
//
// Compared with Prim: Kruskal is preferred when edges are easy to enumerate
// and the graph is sparse; Prim wins for dense graphs where you'd rather
// scan adjacency.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

struct Edge { int u, v, w; };

struct DSU {
    vector<int> p, r;
    DSU(int n) : p(n), r(n, 0) { iota(p.begin(), p.end(), 0); }
    int find(int x) {
        while (p[x] != x) { p[x] = p[p[x]]; x = p[x]; }
        return x;
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
        return true;
    }
};

pair<long long, vector<Edge>> kruskal(int n, vector<Edge> edges) {
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });
    DSU d(n);
    long long total = 0;
    vector<Edge> mst;
    for (auto& e : edges) {
        if (d.unite(e.u, e.v)) {
            total += e.w;
            mst.push_back(e);
            if ((int)mst.size() == n - 1) break;
        }
    }
    return {total, mst};
}

int main() {
    int n = 4;
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
    };
    auto [total, mst] = kruskal(n, edges);
    cout << "MST total weight: " << total << endl;
    cout << "MST edges:" << endl;
    for (auto& e : mst) cout << "  " << e.u << " - " << e.v << " (w=" << e.w << ")" << endl;
    return 0;
}
