// In The Name of Allah

// 0-1 BFS
//
// Problem:   Single-source shortest paths when every edge weight is 0 or 1.
// Approach:  Standard BFS, but use a deque: push a 0-weight edge to the front
//            and a 1-weight edge to the back. This maintains the invariant
//            that the deque holds vertices in non-decreasing distance order,
//            so popping from the front always yields the next-closest vertex.
// Time:      O(V + E)
// Space:     O(V)
//
// Common applications: grids where some moves are free and some cost one,
// or graphs with two distinct edge weights.

#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

vector<int> bfs_01(int n, const vector<vector<pair<int,int>>>& adj, int src) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    deque<int> dq;
    dq.push_front(src);
    while (!dq.empty()) {
        int u = dq.front(); dq.pop_front();
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (w == 0) dq.push_front(v);
                else dq.push_back(v);
            }
        }
    }
    return dist;
}

int main() {
    int n = 6;
    vector<vector<pair<int,int>>> adj(n);
    auto add = [&](int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };
    add(0, 1, 1);
    add(0, 2, 0);
    add(1, 2, 1);
    add(1, 3, 0);
    add(2, 4, 1);
    add(3, 4, 1);
    add(3, 5, 0);
    add(4, 5, 1);

    auto dist = bfs_01(n, adj, 0);
    cout << "Distances from 0:" << endl;
    for (int i = 0; i < n; i++) cout << "  to " << i << " = " << dist[i] << endl;
    return 0;
}
