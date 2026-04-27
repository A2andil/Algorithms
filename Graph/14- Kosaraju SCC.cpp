// In The Name of Allah

// Kosaraju's Strongly Connected Components
//
// Problem:   Decompose a directed graph into SCCs.
// Approach:  Two DFS passes:
//              1. DFS on the graph, push vertices onto a stack in finish order.
//              2. DFS on the *transpose* graph in reverse finish order; each
//                 traversal yields one SCC.
// Time:      O(V + E)
// Space:     O(V + E)
//
// Conceptually simpler than Tarjan but does two passes over the graph.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class KosarajuSCC {
    int n;
    vector<vector<int>> adj, radj;
    vector<bool> visited;
    stack<int> order;
public:
    vector<vector<int>> sccs;

    KosarajuSCC(int n) : n(n), adj(n), radj(n), visited(n, false) {}

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    void dfs1(int u) {
        visited[u] = true;
        for (int v : adj[u]) if (!visited[v]) dfs1(v);
        order.push(u);
    }

    void dfs2(int u, vector<int>& comp) {
        visited[u] = true;
        comp.push_back(u);
        for (int v : radj[u]) if (!visited[v]) dfs2(v, comp);
    }

    void run() {
        for (int i = 0; i < n; i++) if (!visited[i]) dfs1(i);
        fill(visited.begin(), visited.end(), false);
        while (!order.empty()) {
            int u = order.top(); order.pop();
            if (!visited[u]) {
                vector<int> comp;
                dfs2(u, comp);
                sccs.push_back(comp);
            }
        }
    }
};

int main() {
    KosarajuSCC g(8);
    int edges[][2] = {{0,1},{1,2},{2,0},{1,3},{3,4},{4,5},{5,3},{6,5},{6,7}};
    for (auto& e : edges) g.add_edge(e[0], e[1]);
    g.run();
    cout << "Found " << g.sccs.size() << " SCCs:" << endl;
    for (auto& comp : g.sccs) {
        cout << " {";
        for (int i = 0; i < (int)comp.size(); i++) cout << (i ? ", " : "") << comp[i];
        cout << "}" << endl;
    }
    return 0;
}
