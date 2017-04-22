//in the name of God

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define ll long long
#define oo 1e9 + 7
using namespace std;

inline ll llMin(ll a, ll b) { return a > b ? b : a; }

const int N = 1000;
ll adjMatrix[N][N], floyd[N][N];

void FloydWarshall() {
        for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                        if (i == j) floyd[i][j] = 0;
                        else if (adjMatrix[i][j]) floyd[i][j] = adjMatrix[i][j];
                        else floyd[i][j] = oo;
                }
        }
        for (int k = 1; k <= N; k++) {
                for (int i = 1; i <= N; i++) {
                        for (int j = 1; j <= N; j++) {
                                floyd[i][j] = llMin(floyd[i][j], floyd[i][k] + floyd[k][j]);
                        }
                }
        }
}

int main() {

        return 0;
}
