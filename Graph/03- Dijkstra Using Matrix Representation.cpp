//in the name of God

#include <iostream>
#include <limits.h>

#define sz 9
#define oo INT_MAX

using namespace std;

int MinDistance(int dist[], bool picked[]) {
	int min = oo, minIdx;
	for (int i = 0; i < sz; i++) {
		if (picked[i] == false && dist[i] <= min)
			min = dist[i], minIdx = i;
	}
	return minIdx;
}

void Dijkstra(int Graph[sz][sz], int src) {
	int dist[sz];
	bool picked[sz];
	for (int i = 0; i < sz; i++)
		dist[i] = oo, picked[i] = false;

	dist[src] = 0;

	for (int count = 0; count < sz - 1; count++) {
		int u = MinDistance(dist, picked);
		picked[u] = true;
		for (int v = 0; v < sz; v++) {
			if (!picked[v] && Graph[u][v] && dist[u] != oo
				&& dist[u] + Graph[u][v] < dist[v])
				dist[v] = dist[u] + Graph[u][v];
		}
	}
}

int main() {
	int Graph[sz][sz] = {
		{ 0, 4, 0, 0, 0, 0, 0, 8, 0 },
		{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
		{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
		{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
		{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
		{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
		{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
		{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
		{ 0, 0, 2, 0, 0, 0, 6, 7, 0 }
	};
	Dijkstra(Graph, 1);
	return 0;
}