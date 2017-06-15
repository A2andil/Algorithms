// in the name of God

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define ll long long
using namespace std;

const int MAX = 6;
bool visited[MAX];
vector<int> adjList[MAX];

void dfs(int v, stack<int> &Stack) {
	visited[v] = true;
	for (auto u : adjList[v]) {
		if (!visited[u]) {
			dfs(u, Stack);
		}
	}
	Stack.push(v);
}

void toplogicalSort() {
	stack<int> Stack;
	for (int i = 0; i < MAX; i++)
		visited[i] = false;
	for (int i = 0; i < MAX; i++) {
		if (!visited[i])
			dfs(i, Stack);
	}
	while (!Stack.empty()) {
		cout << Stack.top() << " ";
		Stack.pop();
	}
}

int main() {
	adjList[5].push_back(2);
	adjList[5].push_back(0);
	adjList[4].push_back(0);
	adjList[4].push_back(1);
	adjList[2].push_back(3);
	adjList[3].push_back(1);
	toplogicalSort();
	return 0;
}
