// In The Name of Allah

// Dijkstra with Path Reconstruction
//
// Problem:   Find the shortest path from src to dst in a non-negative
//            weighted graph, AND return the actual sequence of vertices.
// Approach:  Standard Dijkstra, but maintain parent[v] = the predecessor of v
//            along the best path discovered so far. Reconstruct the path by
//            walking parent[] from dst back to src and reversing.
// Time:      O((V + E) log V)
// Space:     O(V + E)

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

const int INF = INT_MAX;

pair<int, vector<int>> dijkstra_path(int n, const vector<vector<pair<int,int>>>& adj,
                                     int src, int dst) {
    vector<int> dist(n, INF), parent(n, -1);
    dist[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    vector<int> path;
    if (dist[dst] == INF) return {INF, path};
    for (int v = dst; v != -1; v = parent[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    return {dist[dst], path};
}

int main() {
    int n = 9;
    vector<vector<pair<int,int>>> adj(n);
    auto add = [&](int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };
    add(0, 1, 4);  add(0, 7, 8);  add(1, 2, 8);  add(1, 7, 11);
    add(2, 3, 7);  add(2, 8, 2);  add(2, 5, 4);  add(3, 4, 9);
    add(3, 5, 14); add(4, 5, 10); add(5, 6, 2);  add(6, 7, 1);
    add(6, 8, 6);  add(7, 8, 7);

    auto [d, path] = dijkstra_path(n, adj, 0, 4);
    cout << "Shortest distance from 0 to 4: " << d << endl;
    cout << "Path:";
    for (int v : path) cout << " " << v;
    cout << endl;
    return 0;
}
