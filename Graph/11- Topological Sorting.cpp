// In The Name of Allah

// Topological Sort (DFS-based)
//
// Problem:   Linearly order the vertices of a Directed Acyclic Graph so that
//            for every edge u -> v, u appears before v.
// Approach:  DFS, push each vertex onto a stack at the moment its DFS call
//            finishes. The reversed finish order is a valid topological
//            ordering. (For an alternative, see Kahn's BFS-based variant
//            using in-degrees.)
// Time:      O(V + E)
// Space:     O(V)
//
// Used in build systems, course-prerequisite scheduling, and as a setup pass
// for shortest paths in DAGs.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class TopoSort {
    int n;
    vector<vector<int>> adj;
    vector<bool> visited;
    void dfs(int u, stack<int>& s) {
        visited[u] = true;
        for (int v : adj[u]) if (!visited[v]) dfs(v, s);
        s.push(u);
    }
public:
    TopoSort(int n) : n(n), adj(n), visited(n, false) {}
    void add_edge(int u, int v) { adj[u].push_back(v); }
    vector<int> sort() {
        stack<int> s;
        fill(visited.begin(), visited.end(), false);
        for (int i = 0; i < n; i++) if (!visited[i]) dfs(i, s);
        vector<int> order;
        while (!s.empty()) { order.push_back(s.top()); s.pop(); }
        return order;
    }
};

int main() {
    TopoSort g(6);
    g.add_edge(5, 2);
    g.add_edge(5, 0);
    g.add_edge(4, 0);
    g.add_edge(4, 1);
    g.add_edge(2, 3);
    g.add_edge(3, 1);

    auto order = g.sort();
    cout << "Topological order:";
    for (int v : order) cout << " " << v;
    cout << endl;
    return 0;
}
