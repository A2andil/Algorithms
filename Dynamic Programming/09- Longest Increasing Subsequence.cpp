//In The Name of Allah
#include <algorithm>
#include <iostream>
using namespace std;

const int sz = (int)1e6;
int dp[sz];

int lis(int arr[], int n) {
	int i, j, mx = 0;
	for (i = 0; i < n; i++)
		dp[i] = 1;
	for (i = 1; i < n; i++) {
		for (j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
			mx = max(dp[i], mx);
		}
	}
	return mx;
}
int main() {
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int n = sizeof(arr) / sizeof(int);
	cout << "Length of lis is " << lis(arr, n) << endl;
	return 0;
}