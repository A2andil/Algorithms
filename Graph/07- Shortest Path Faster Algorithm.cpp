// In The Name of Allah

// SPFA — Shortest Path Faster Algorithm
//
// Problem:   Single-source shortest paths in a graph with possibly negative
//            edge weights (no negative cycles assumed for the basic version).
// Approach:  Bellman-Ford reformulated as a queue-based relaxation: only
//            re-process a vertex when its distance has improved. In practice
//            much faster than naive Bellman-Ford on sparse random graphs,
//            though the worst case is still O(V*E).
// Time:      O(k*E) average where k is small; O(V*E) worst case
// Space:     O(V + E)

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<long long> spfa(int n, const vector<vector<pair<int,int>>>& adj, int src) {
    const long long INF = LLONG_MAX / 2;
    vector<long long> dist(n, INF);
    vector<bool> in_queue(n, false);
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    in_queue[src] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        in_queue[u] = false;
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (!in_queue[v]) {
                    q.push(v);
                    in_queue[v] = true;
                }
            }
        }
    }
    return dist;
}

int main() {
    int n = 5;
    vector<vector<pair<int,int>>> adj(n);
    auto add = [&](int u, int v, int w) { adj[u].push_back({v, w}); };
    add(0, 1, 6); add(0, 2, 7); add(1, 2, 8); add(1, 3, 5); add(1, 4, -4);
    add(2, 3, -3); add(2, 4, 9); add(3, 1, -2); add(4, 0, 2); add(4, 3, 7);
    auto dist = spfa(n, adj, 0);
    cout << "Distances from 0:" << endl;
    for (int i = 0; i < n; i++) cout << "  to " << i << " = " << dist[i] << endl;
    return 0;
}
