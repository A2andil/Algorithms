// In The Name of Allah

// Dijkstra's Shortest Path (adjacency list + binary heap)
//
// Problem:   Single-source shortest paths in a graph with non-negative
//            edge weights.
// Approach:  Adjacency list + min-heap (priority queue) keyed on distance.
//            Each vertex is popped at most once and we may insert duplicates;
//            stale entries are skipped on pop. This is the standard
//            "lazy deletion" formulation.
// Time:      O((V + E) log V)
// Space:     O(V + E)

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int INF = INT_MAX;

vector<int> dijkstra(int n, const vector<vector<pair<int,int>>>& adj, int src) {
    vector<int> dist(n, INF);
    dist[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
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

    auto dist = dijkstra(n, adj, 0);
    cout << "Distances from 0:" << endl;
    for (int i = 0; i < n; i++) cout << "  to " << i << " = " << dist[i] << endl;
    return 0;
}
