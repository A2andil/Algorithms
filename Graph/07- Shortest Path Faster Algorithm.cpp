//in the name of God

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define ll long long
#define oo 1e9 + 7
using namespace std;

const int N = 5;
vector<pair<int, int>> list[N];
int dist[N], exist[N];
queue<int> q;

void SPFA(int s) {
        for (int i = 0; i < N; i++) dist[i] = oo, exist[i] = 0;
        dist[s] = 0;
        q.push(s);
        while (!q.empty()) {
                int a = q.front(); q.pop();
                exist[a] = 0;
                for (auto b : list[a]) {
                        if (dist[a] + b.second < b.first) {
                                dist[b.first] = dist[a] + b.second;
                                if (!exist[b.first]) {
                                        q.push(b.first);
                                        exist[b.first] = 1;
                                }
                        }
                }
        }
}

int main() {

        return 0;
}
