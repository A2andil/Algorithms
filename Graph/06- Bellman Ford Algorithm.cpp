// In The Name of Allah

// Bellman-Ford Shortest Paths
//
// Problem:   Single-source shortest paths in a graph that may contain
//            NEGATIVE edge weights. Detects reachable negative cycles.
// Approach:  Relax every edge V-1 times. Any further relaxation in pass V
//            indicates a negative cycle reachable from src.
// Time:      O(V * E)
// Space:     O(V)
//
// Use when negative weights are present. For non-negative weights, Dijkstra
// is faster. SPFA (file 07) is the same algorithm with a queue, faster on
// average but the same worst case.

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge { int u, v, w; };

bool bellman_ford(int n, const vector<Edge>& edges, int src,
                  vector<long long>& dist) {
    const long long INF = LLONG_MAX / 2;
    dist.assign(n, INF);
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++) {
        bool changed = false;
        for (auto& e : edges) {
            if (dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                changed = true;
            }
        }
        if (!changed) break;
    }
    // detect negative cycle reachable from src
    for (auto& e : edges) {
        if (dist[e.u] + e.w < dist[e.v]) return false;
    }
    return true;
}

int main() {
    int n = 5;
    vector<Edge> edges = {
        {0, 1, 6}, {0, 2, 7}, {1, 2, 8}, {1, 3, 5}, {1, 4, -4},
        {2, 3, -3}, {2, 4, 9}, {3, 1, -2}, {4, 0, 2}, {4, 3, 7}
    };
    vector<long long> dist;
    bool ok = bellman_ford(n, edges, 0, dist);
    if (!ok) {
        cout << "Negative cycle detected" << endl;
    } else {
        cout << "Distances from 0:" << endl;
        for (int i = 0; i < n; i++) cout << "  to " << i << " = " << dist[i] << endl;
    }
    return 0;
}
