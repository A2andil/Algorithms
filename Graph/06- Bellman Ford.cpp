//in the name of God

#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
#define oo 1e9 + 7
using namespace std;

const int N = 5;
vector<pair<int, int>> list[N];
int dist[N];

inline ll llMin(ll a, ll b) { return a < b ? a : b; }

void BellmanFord(int s) {
        for (int i = 0; i < N; i++) dist[i] = oo;
        dist[s] = 0;
        for (int i = 0; i < N - 1; i++) {
                for (int j = 0; j < N; j++) {
                        for (auto x : list[j]) {
                                dist[x.first] = llMin(dist[x.second], dist[j] + x.second);
                        }
                }
        }
}

int main() {

        return 0;
}
