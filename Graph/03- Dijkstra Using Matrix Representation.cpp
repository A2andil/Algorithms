// In The Name of Allah

// Dijkstra's Shortest Path (adjacency matrix)
//
// Problem:   Single-source shortest paths in a graph with non-negative
//            edge weights.
// Approach:  Repeatedly pick the unvisited vertex u with smallest tentative
//            distance, mark it final, and relax every neighbor of u. Picking
//            the min by linear scan over n vertices gives O(V^2) total.
// Time:      O(V^2)
// Space:     O(V^2) for the matrix, O(V) for the work arrays
//
// O(V^2) is the right choice for dense graphs. For sparse graphs use the
// adjacency-list + heap version (see 04- Dijkstra Using List Representation.cpp).

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int SZ = 9;
const int INF = INT_MAX;

int min_distance(const vector<int>& dist, const vector<bool>& picked) {
    int mn = INF, idx = -1;
    for (int i = 0; i < SZ; i++) {
        if (!picked[i] && dist[i] <= mn) { mn = dist[i]; idx = i; }
    }
    return idx;
}

vector<int> dijkstra(int graph[SZ][SZ], int src) {
    vector<int> dist(SZ, INF);
    vector<bool> picked(SZ, false);
    dist[src] = 0;
    for (int count = 0; count < SZ - 1; count++) {
        int u = min_distance(dist, picked);
        if (u == -1) break;
        picked[u] = true;
        for (int v = 0; v < SZ; v++) {
            if (!picked[v] && graph[u][v] && dist[u] != INF
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    return dist;
}

int main() {
    int graph[SZ][SZ] = {
        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    };
    auto dist = dijkstra(graph, 0);
    cout << "Distances from 0:" << endl;
    for (int i = 0; i < SZ; i++) cout << "  to " << i << " = " << dist[i] << endl;
    return 0;
}
