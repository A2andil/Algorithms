//In The Name Of Allah
#include <algorithm>
#include <iostream>
#define oo 1e9
using namespace std;

const int sz = 1000;
int val[sz];

int cutRod(int price[], int n) {
	val[0] = 0;
	int i, j;
	for (i = 1; i <= n; i++) {
		int max_val = -oo;
		for (j = 0; j < i; j++)
			max_val = max(max_val, price[j] + val[i - j - 1]);
		val[i] = max_val;
	}
	return val[n];
}

int main() {
	int a[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
	int size = sizeof(a) / sizeof(int);
	cout << "maximum profit : " << cutRod(a, size) << endl;
	return 0;
}
