//In The Name Of Allah
#include <algorithm>
#include <iostream>
using namespace std;

int MaximumSub(int arr[], int sz) {
	int rs = arr[0], mx = arr[0];
	for (int i = 1; i < sz; i++) {
		mx = max(arr[i], mx + arr[i]);
		rs = max(rs, mx);
	}
	return rs;
}
int main() {
	int arr[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
	int n = sizeof(arr) / sizeof(int);
	int rs = MaximumSub(arr, n);
	cout << "Maximum Subarray Sum is " << rs << endl;
	return 0;
}
