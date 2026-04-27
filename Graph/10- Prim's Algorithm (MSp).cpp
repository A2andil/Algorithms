// In The Name of Allah

// Prim's Minimum Spanning Tree
//
// Problem:   In a connected weighted undirected graph, find a spanning tree
//            of minimum total weight.
// Approach:  Grow the MST one vertex at a time, always adding the cheapest
//            edge that crosses from the tree to a vertex outside it.
//            Implemented here with a binary heap.
// Time:      O((V + E) log V)
// Space:     O(V + E)

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

pair<long long, vector<pair<int,int>>> prim(int n, const vector<vector<pair<int,int>>>& adj) {
    vector<int> key(n, INT_MAX), parent(n, -1);
    vector<bool> in_mst(n, false);
    key[0] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, 0});
    long long total = 0;
    while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (in_mst[u]) continue;
        in_mst[u] = true;
        total += w;
        for (auto [v, weight] : adj[u]) {
            if (!in_mst[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({weight, v});
            }
        }
    }
    vector<pair<int,int>> mst;
    for (int v = 1; v < n; v++) if (parent[v] != -1) mst.push_back({parent[v], v});
    return {total, mst};
}

int main() {
    int n = 5;
    vector<vector<pair<int,int>>> adj(n);
    auto add = [&](int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };
    add(0, 1, 2); add(0, 3, 6); add(1, 2, 3); add(1, 3, 8); add(1, 4, 5);
    add(2, 4, 7); add(3, 4, 9);

    auto [total, mst] = prim(n, adj);
    cout << "MST total weight: " << total << endl;
    cout << "MST edges:" << endl;
    for (auto& e : mst) cout << "  " << e.first << " - " << e.second << endl;
    return 0;
}
