// In The Name of Allah

// Articulation Points and Bridges (Tarjan, undirected graph)
//
// Problem:   In an undirected graph:
//              - an articulation point is a vertex whose removal increases the
//                number of connected components
//              - a bridge is an edge whose removal increases the number of
//                connected components
// Approach:  DFS computing disc[v] (discovery time) and low[v] (lowest disc
//            reachable from v's subtree using at most one back edge).
//              - edge (u, v) is a bridge iff low[v] > disc[u]
//              - non-root u is an articulation point iff some child v has
//                low[v] >= disc[u]
//              - the DFS root is an articulation point iff it has >= 2 children
// Time:      O(V + E)
// Space:     O(V)

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class GraphCC {
    int n, timer = 0;
    vector<vector<int>> adj;
    vector<int> disc, low;
public:
    set<int> articulation_points;
    vector<pair<int,int>> bridges;

    GraphCC(int n) : n(n), adj(n), disc(n, -1), low(n, 0) {}

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int parent) {
        disc[u] = low[u] = timer++;
        int children = 0;
        for (int v : adj[u]) {
            if (disc[v] == -1) {
                children++;
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (parent != -1 && low[v] >= disc[u]) articulation_points.insert(u);
                if (low[v] > disc[u]) bridges.push_back({min(u, v), max(u, v)});
            } else if (v != parent) {
                low[u] = min(low[u], disc[v]);
            }
        }
        if (parent == -1 && children > 1) articulation_points.insert(u);
    }

    void run() {
        for (int i = 0; i < n; i++) if (disc[i] == -1) dfs(i, -1);
    }
};

int main() {
    GraphCC g(7);
    int edges[][2] = {{0,1},{1,2},{2,0},{1,3},{3,4},{4,5},{5,6},{4,6}};
    for (auto& e : edges) g.add_edge(e[0], e[1]);
    g.run();

    cout << "Articulation points:";
    for (int v : g.articulation_points) cout << " " << v;
    cout << endl;

    cout << "Bridges:";
    for (auto& e : g.bridges) cout << " (" << e.first << "," << e.second << ")";
    cout << endl;
    return 0;
}
