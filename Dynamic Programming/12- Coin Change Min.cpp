// In The Name of Allah

// Coin Change — minimum number of coins
//
// Problem:   Given coin denominations and an amount A, return the minimum
//            number of coins that sum exactly to A, or -1 if impossible.
//            Each denomination may be used unlimited times.
// Approach:  dp[a] = min coins to make amount a. Transition:
//              dp[a] = 1 + min over coin c of dp[a - c], if a - c >= 0.
// Time:      O(n * A) where n = number of denominations, A = target amount
// Space:     O(A)

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int min_coins(const vector<int>& coins, int A) {
    const int INF = INT_MAX / 2;
    vector<int> dp(A + 1, INF);
    dp[0] = 0;
    for (int a = 1; a <= A; a++) {
        for (int c : coins) {
            if (c <= a) dp[a] = min(dp[a], dp[a - c] + 1);
        }
    }
    return dp[A] >= INF ? -1 : dp[A];
}

int main() {
    vector<int> coins = {1, 3, 4};
    cout << "min coins for 6 with {1,3,4} = " << min_coins(coins, 6) << endl;

    coins = {2};
    cout << "min coins for 3 with {2} = " << min_coins(coins, 3) << endl;

    coins = {1, 5, 10, 25};
    cout << "min coins for 63 with US-like {1,5,10,25} = " << min_coins(coins, 63) << endl;
    return 0;
}
