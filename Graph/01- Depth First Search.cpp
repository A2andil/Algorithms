// In The Name of Allah

// Depth-First Search
//
// Problem:   Visit every reachable vertex of a graph.
// Approach:  Recurse on the current vertex, marking visited and descending
//            into each unvisited neighbor before backtracking.
// Time:      O(V + E)
// Space:     O(V) for visited set + recursion stack
//
// Building block for: cycle detection, topological sort, SCCs (Tarjan,
// Kosaraju), articulation points / bridges, connected components.

#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    void dfs_util(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";
        for (int u : adj[v]) if (!visited[u]) dfs_util(u, visited);
    }
public:
    Graph(int V) : V(V), adj(V) {}
    void add_edge(int v, int w) { adj[v].push_back(w); }
    void dfs() {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) if (!visited[i]) dfs_util(i, visited);
    }
    void dfs_from(int src) {
        vector<bool> visited(V, false);
        dfs_util(src, visited);
    }
};

int main() {
    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);

    cout << "DFS from 2: ";
    g.dfs_from(2);
    cout << endl;

    cout << "DFS over all components: ";
    g.dfs();
    cout << endl;
    return 0;
}
