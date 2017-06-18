// in the name of God

#include <iostream>
#include <limits>

#define ll long long
using namespace std;

class MinHeap {
private:
	ll *list, capacity, size;
	void minHeapify(int i) {
		int l = 2 * i + 1, r = 2 * i + 2, idx;
		idx = l < size && list[l] < list[i] ? l : i;
		idx = r < size && list[r] < list[idx] ? r : idx;
		if (idx != i) {
			swap(list[i], list[idx]);
			minHeapify(idx);
		}
	}
public:
	MinHeap(int sz) {
		size = 0, capacity = sz, list = new ll[sz];
	}
	ll extractMin() {
		if (size <= 0) return INT_MAX;
		else if (size == 1) {
			size = 0;
			return list[0];
		}
		ll root = list[0];
		list[0] = list[size - 1], size = size - 1;
		minHeapify(0);
		return root;
	}
	void insertKey(ll k) {
		int i = size;
		list[i] = k, size = size + 1;
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
			hp->insertKey(list[i]);
		}
		for (int i = 0; i < sz; i++) {
			list[i] = hp->extractMin();
		}
	}
};

int main() {
	return 0;
}
