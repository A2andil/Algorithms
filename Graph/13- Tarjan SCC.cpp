// In The Name of Allah

// Tarjan's Strongly Connected Components
//
// Problem:   Decompose a directed graph into maximal subsets where every
//            vertex is reachable from every other vertex.
// Approach:  Single DFS. For each vertex track disc[v] (discovery time) and
//            low[v] (smallest disc reachable via the subtree + at most one
//            back edge). Vertices on a stack form the currently-open SCCs;
//            when low[v] == disc[v], pop until v to emit one SCC.
// Time:      O(V + E)
// Space:     O(V)

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class TarjanSCC {
    int n, timer = 0;
    vector<vector<int>> adj;
    vector<int> disc, low;
    vector<bool> on_stack;
    stack<int> stk;
public:
    vector<vector<int>> sccs;

    TarjanSCC(int n) : n(n), adj(n), disc(n, -1), low(n, 0), on_stack(n, false) {}

    void add_edge(int u, int v) { adj[u].push_back(v); }

    void dfs(int u) {
        disc[u] = low[u] = timer++;
        stk.push(u);
        on_stack[u] = true;
        for (int v : adj[u]) {
            if (disc[v] == -1) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (on_stack[v]) {
                low[u] = min(low[u], disc[v]);
            }
        }
        if (low[u] == disc[u]) {
            vector<int> comp;
            while (true) {
                int v = stk.top(); stk.pop();
                on_stack[v] = false;
                comp.push_back(v);
                if (v == u) break;
            }
            sccs.push_back(comp);
        }
    }

    void run() {
        for (int i = 0; i < n; i++) if (disc[i] == -1) dfs(i);
    }
};

int main() {
    TarjanSCC g(8);
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
