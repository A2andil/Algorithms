//in the name of God

#include <iostream>
#include <limits>

#define ll long long
using namespace std;

class MinHeap {
private:
        ll *list, capacity, size;
        void MinHeapify(int i) {
                int l = 2 * i + 1;
                int r = 2 * i + 2;
                int smallest = i;
                if (l < size && list[l] < list[i])
                        smallest = l;
                if (r < size && list[r] < list[smallest])
                        smallest = r;
                if (smallest != i) {
                        swap(list[i], list[smallest]);
                        MinHeapify(smallest);
                }
        }
public:
        MinHeap(int sz) {
                size = 0;
                capacity = sz;
                list = new ll[sz];
        }
        ll ExtractMin() {
                if (size <= 0)
                        return INT_MAX;
                if (size == 1) {
                        size = size - 1;
                        return list[0];
                }
                ll root = list[0];
                list[0] = list[size - 1];
                size = size - 1;
                MinHeapify(0);
                return root;
        }
        void InsertKey(ll k) {
                if (size == capacity) {
                        cout << "Overflow: Could not insertKey" << endl;
                        return;
                }
                size = size + 1;
                int i = size - 1;
                list[i] = k;
                while (i != 0 && list[(i - 1) / 2] > list[i]) {
                        swap(list[i], list[(i - 1) / 2]);
                        i = (i - 1) / 2;
                }
        }
};

class HeapSort {
private:
        MinHeap *hp;
public:
        HeapSort(ll list[], int sz) {
                hp = new MinHeap(sz);
                for (int i = 0; i < sz; i++) {
                        hp->InsertKey(list[i]);
                }
                for (int i = 0; i < sz; i++) {
                        list[i] = hp->ExtractMin();
                }
        }
};

int main() {
        ll list[] = { 1, 5, -1, 20, 0, 5 };
        int sz = sizeof(list) / sizeof(ll);
        HeapSort *hSort = new HeapSort(list, sz);
        for (int i = 0; i < sz; i++) {
                cout << list[i] << ' ';
        }
        cout << endl;
        return 0;
}
