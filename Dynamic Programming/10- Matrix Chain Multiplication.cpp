// In The Name of Allah

// Matrix Chain Multiplication
//
// Problem:   Given matrices A1..An whose dimensions are encoded in p[] such
//            that Ai has size p[i-1] x p[i], find the minimum number of
//            scalar multiplications needed to compute the full product.
//            (Multiplication is associative, so the only choice is HOW to
//            parenthesize the chain.)
// Approach:  dp[i][j] = min scalar mults to compute the subchain Ai..Aj.
//              dp[i][i] = 0
//              dp[i][j] = min over k in [i..j-1] of
//                            dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j]
// Time:      O(n^3)
// Space:     O(n^2)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrix_chain(const vector<int>& p) {
    int n = (int)p.size();
    if (n < 2) return 0;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < dp[i][j]) dp[i][j] = q;
            }
        }
    }
    return dp[1][n - 1];
}

int main() {
    // Three matrices: 1x2, 2x3, 3x4. Encoded as {1,2,3,4}.
    vector<int> p = {1, 2, 3, 4};
    cout << "Min multiplications for {1x2, 2x3, 3x4}: " << matrix_chain(p) << endl;

    // 40x20, 20x30, 30x10, 10x30 → encoded as {40,20,30,10,30}.
    p = {40, 20, 30, 10, 30};
    cout << "Min multiplications for 4-chain example: " << matrix_chain(p) << endl;
    return 0;
}
