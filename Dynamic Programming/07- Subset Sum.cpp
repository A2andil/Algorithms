//in the name of God

#include <iostream>
using namespace std;

const int sz = 1000, sum = 1000;
bool dp[sum][sz];

bool SubsetSum(int set[], int n, int sum) {
	for (int i = 0; i <= n; i++)
		dp[0][i] = true;
	for (int i = 1; i <= sum; i++)
		dp[i][0] = false;
	for (int i = 1; i <= sum; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = dp[i][j - 1];
			if (i >= set[j - 1])
				dp[i][j] = dp[i][j] || dp[i - set[j - 1]][j - 1];
		}
	}
	return dp[sum][n];
}
int main() {
	int set[] = { 3, 34, 4, 12, 5, 2 };
	int sum = 9, n = sizeof(set) / sizeof(set[0]);
	if (SubsetSum(set, n, sum) == true)
		cout << "Found a dp with given sum" << endl;
	else
		cout << "No dp with given sum" << endl;
	return 0;
}
