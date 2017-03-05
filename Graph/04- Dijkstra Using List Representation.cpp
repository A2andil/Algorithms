//in the name of God

#include <iostream>
#include <limits>
#include <stack>

#define oo INT_MAX
#define ll long long

using namespace std;

struct Node {
        int dest, weight;
        Node *next;
};

struct AdjList {
        Node *head;
};

class Graph {
private:
        Node* createNode(int dest, int weight) {
                Node *nd = (Node*)malloc(sizeof(Node));
                nd->dest = dest;
                nd->weight = weight;
                nd->next = 0;
                return nd;
        }
public:
        int size;
        AdjList *graph;
        Graph(int sz) {
                size = sz;
                graph = new AdjList[sz];
                for (int i = 0; i < sz; i++) {
                        graph[i].head = 0;
                }
        }

        void AddEdge(int src, int dest, int weight) {
                Node *nd = createNode(dest, weight);
                nd->next = graph[src].head;
                graph[src].head = nd;

                nd = createNode(src, weight);
                nd->next = graph[dest].head;
                graph[dest].head = nd;
        }
};

struct HeapNode {
        int  v, dist;
};

class Heap {
public:
        int size, cap, *pos;
        HeapNode **list;

        Heap(int cap) {
                this->cap = cap;
                pos = (int *)malloc(cap * sizeof(int));
                size = 0;
                list = new HeapNode*[cap];
        }

        int isEmpty() {
                return size == 0;
        }

        HeapNode* extractMin() {
                if (isEmpty())
                        return 0;
                HeapNode *root = list[0];
                list[0] = list[size - 1];
                pos[root->v] = size - 1;
                pos[list[0]->v] = 0;
                size = size - 1;

                hpify(0);

                return root;
        }

        void updateValue(int v, int dist) {
                int i = pos[v];
                list[i]->dist = dist;

                while (i && list[i]->dist < list[(i - 1) / 2]->dist) {
                        pos[list[i]->v] = (i - 1) / 2;
                        pos[list[(i - 1) / 2]->v] = i;
                        swap(&list[i], &list[(i - 1) / 2]);
                        i = (i - 1) / 2;
                }
        }

        bool isInHeap(int v) {
                if (pos[v] < size)
                        return true;
                return false;
        }

        HeapNode* createNode(int v, int dist) {
                HeapNode *nd = (HeapNode*)malloc(sizeof(HeapNode));
                nd->v = v;
                nd->dist = dist;
                return nd;
        }
private:
        void swap(HeapNode** a, HeapNode** b) {
                HeapNode *s = *a;
                *a = *b, *b = s;
        }
        void hpify(int idx) {
                int smallest = idx, left = 2 * idx + 1, right = 2 * idx + 2;
                if (left < size &&
                        list[left]->dist < list[smallest]->dist)
                        smallest = left;

                if (right < size &&
                        list[right]->dist < list[smallest]->dist)
                        smallest = right;

                if (smallest != idx) {
                        HeapNode *smallestNode = list[smallest];
                        HeapNode *idxNode = list[idx];

                        pos[smallestNode->v] = idx;
                        pos[idxNode->v] = smallest;

                        swap(&list[smallest], &list[idx]);

                        hpify(smallest);
                }
        }
};

class Dijkstra{
private:
        int *dist, *parent;
public:
        Dijkstra(Graph *G, int src) {
                dist = new int[G->size];
                parent = new int[G->size];
                Heap *hp = new Heap(G->size);

                for (int i = 0; i < G->size; ++i) {
                        dist[i] = oo, parent[i] = -1;
                        hp->list[i] = hp->createNode(i, dist[i]);
                        hp->pos[i] = i;
                }

                dist[src] = 0;
                hp->updateValue(src, dist[src]);
                hp->size = G->size;

                while (!hp->isEmpty()) {
                        HeapNode *nd = hp->extractMin();
                        int u = nd->v;
                        Node *head = G->graph[u].head;
                        while (head != 0) {
                                int v = head->dest;
                                if (hp->isInHeap(v) && dist[u] != oo &&
                                        head->weight + dist[u] < dist[v]) {
                                        parent[v] = u;
                                        dist[v] = dist[u] + head->weight;
                                        hp->updateValue(v, dist[v]);
                                }
                                head = head->next;
                        }
                }
        }

        void path(int dest) {
                int temp = dest;
                stack<int> rs;
                while (temp != -1) {
                        rs.push(temp);
                        temp = parent[temp];
                }
                while (!rs.empty()) {
                        if (rs.size() > 1)
                                cout << rs.top() << " => ";
                        else cout << rs.top() << endl;
                        rs.pop();
                }
        }

        void distance(int dest) {
                cout << dist[dest] << endl;
        }
};

int main() {
        int sz = 9;
        Graph *G = new Graph(sz);

        G->AddEdge(0, 1, 4);
        G->AddEdge(0, 7, 8);
        G->AddEdge(1, 2, 8);
        G->AddEdge(1, 7, 11);
        G->AddEdge(2, 3, 7);
        G->AddEdge(2, 8, 2);
        G->AddEdge(2, 5, 4);
        G->AddEdge(3, 4, 9);
        G->AddEdge(3, 5, 14);
        G->AddEdge(4, 5, 10);
        G->AddEdge(5, 6, 2);
        G->AddEdge(6, 7, 1);
        G->AddEdge(6, 8, 6);
        G->AddEdge(7, 8, 7);

        Dijkstra *dijkstra = new Dijkstra(G, 0);
        dijkstra->path(4);
        dijkstra->distance(4);
        return 0;
}
