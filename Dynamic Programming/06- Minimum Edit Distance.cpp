//In The Name Of Allah
#include <algorithm>
#include <iostream>
using namespace std;

const int sz = 1000;
int dp[sz][sz];

int min(int a, int b, int c) {
	return min(min(a, b), c);
}
int EditDistance(string X, string Y, int m, int n) {
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0) 
				dp[i][j] = i + j;
			else if (X[i - 1] == Y[j - 1]) 
				dp[i][j] = dp[i - 1][j - 1];
			else 
				dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
		}
	}
	return dp[m][n];
}
int main() {
	string X = "sunday", Y = "saturday";
	cout << EditDistance(X, Y, X.length(), Y.length()) << endl;
	return 0;
}