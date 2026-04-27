// In The Name of Allah

// Rod Cutting
//
// Problem:   A rod of length n can be cut into integer-length pieces. Given
//            price[i] = sale price of a piece of length i (for i in 1..k),
//            find the maximum revenue achievable by cutting the rod.
// Approach:  dp[i] = max revenue for a rod of length i.
//              dp[i] = max over j in [1..i] of price[j] + dp[i - j]
// Time:      O(n^2)
// Space:     O(n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cut_rod(const vector<int>& price, int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int best = 0;
        for (int j = 1; j <= i && j < (int)price.size(); j++) {
            best = max(best, price[j] + dp[i - j]);
        }
        dp[i] = best;
    }
    return dp[n];
}

int main() {
    // price[i] = revenue for a piece of length i; price[0] is unused.
    vector<int> price = {0, 1, 5, 8, 9, 10, 17, 17, 20};
    int n = 8;
    cout << "Max revenue for rod of length " << n << ": " << cut_rod(price, n) << endl;
    n = 4;
    cout << "Max revenue for rod of length " << n << ": " << cut_rod(price, n) << endl;
    return 0;
}
