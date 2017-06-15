//in the name of God

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define ll long long
using namespace std;

const int N = 5;
vector<int> list[N];
int visited[N], level[N];
queue<int> q;

void bfs(int s) {
        q.push(s);
        level[s] = 0;
        while (!q.empty()) {
                s = q.front(), visited[s] = 1;
                q.pop();
                for (auto x : list[s]) {
                        if (!visited[x]) {
                                level[x] = level[s] + 1;
                                q.push(x);
                        }
                }
        }
}

int main() {

        return 0;
}
