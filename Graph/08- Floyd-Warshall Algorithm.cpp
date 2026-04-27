// In The Name of Allah

// Floyd-Warshall (All-Pairs Shortest Paths)
//
// Problem:   Compute the shortest distance between every pair of vertices.
//            Works with negative edges too (but not negative cycles).
// Approach:  dp[k][i][j] = min(dp[k-1][i][j], dp[k-1][i][k] + dp[k-1][k][j])
//            collapsed into an in-place 2D matrix. After processing all k,
//            dp[i][j] is the shortest path length from i to j.
// Time:      O(V^3)
// Space:     O(V^2)
//
// Right choice for dense graphs or when you need every pair's distance.
// For sparse graphs, running Dijkstra V times is asymptotically better.

#include <iostream>
#include <vector>
using namespace std;

const long long INF = (long long)1e18;

void floyd_warshall(vector<vector<long long>>& d) {
    int n = (int)d.size();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (d[i][k] >= INF) continue;
            for (int j = 0; j < n; j++) {
                if (d[k][j] >= INF) continue;
                if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
}

int main() {
    int n = 4;
    vector<vector<long long>> d(n, vector<long long>(n, INF));
    for (int i = 0; i < n; i++) d[i][i] = 0;
    d[0][1] = 5;  d[0][3] = 10;
    d[1][2] = 3;
    d[2][3] = 1;

    floyd_warshall(d);

    cout << "All-pairs shortest distances:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i][j] >= INF) cout << "  INF";
            else cout << "  " << d[i][j];
        }
        cout << endl;
    }
    return 0;
}
