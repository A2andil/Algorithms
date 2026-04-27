// In The Name of Allah

// Breadth-First Search
//
// Problem:   Visit every reachable vertex of a graph in order of distance
//            (number of edges) from a source.
// Approach:  Queue-based traversal: enqueue source, then repeatedly dequeue
//            and enqueue all unvisited neighbors.
// Time:      O(V + E)
// Space:     O(V)
//
// Gives shortest paths in unweighted graphs. For 0/1-weighted edges, see
// 16- 0-1 BFS.cpp; for general non-negative weights, see Dijkstra.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(const vector<vector<int>>& adj, int src, vector<int>& level) {
    int n = (int)adj.size();
    level.assign(n, -1);
    queue<int> q;
    q.push(src);
    level[src] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (level[v] == -1) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);
    auto add = [&](int u, int v) { adj[u].push_back(v); adj[v].push_back(u); };
    add(0, 1); add(0, 2); add(1, 3); add(2, 3); add(3, 4); add(4, 5);

    vector<int> level;
    bfs(adj, 0, level);
    cout << "Levels from 0:" << endl;
    for (int i = 0; i < n; i++) cout << "  " << i << ": " << level[i] << endl;
    return 0;
}
