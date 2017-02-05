//in the name of God

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const int m = 1000, n = 1000;
int dp[m + 1][n + 1];

string lcs(string X, string Y, int m, int n) {
	string ans = "";
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0) dp[i][j] = 0;
			else if (X[i - 1] == Y[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	int i = m, j = n;
	while (dp[i][j]) {
		if (X[i - 1] == Y[j - 1]) {
			ans = X[i - 1] + ans;
			i--, j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1]) i--;
		else j--;
	}
	return ans;
}
int main() {
	string X = "AGGTAB", Y = "GXTXAYB";
	int m = X.size(), n = Y.size();
	cout << "LCS is: " << lcs(X, Y, m, n) << endl;
	return 0;
}
