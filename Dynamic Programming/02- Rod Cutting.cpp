//In The Name Of Allah
#include <algorithm>
#include <iostream>
#include <map>
#define oo 1e9
using namespace std;

const int sz = 1000;
int val[sz];
map<int, int> price;

int cutRod(int n) {
	val[0] = 0;
	int i, j;
	for (i = 1; i <= n; i++) {
		int max_val = -oo;
		for (j = 0; j < i; j++)
			max_val = max(max_val, price[j] + val[i - j - 1]);
		val[i] = max_val;
		price[i] = max(price[i], val[i]);
	}
	return val[n];
}

int main() {
	int a[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
	for (int i = 0; i < 8; i++) price[i] = a[i];
	cout << "Maximum Profit : " << cutRod(8) << endl;
	return 0;
}
