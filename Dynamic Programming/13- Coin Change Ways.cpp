// In The Name of Allah

// Coin Change — number of ways
//
// Problem:   Given coin denominations and an amount A, count the number of
//            distinct ways to make A. Order of coins does not matter:
//            {1,2,2} is the same combination as {2,1,2}.
//            Each denomination may be used unlimited times.
// Approach:  dp[a] = number of ways to make amount a.
//            Iterate coins in the OUTER loop and amounts in the INNER loop;
//            this enforces a fixed coin order and avoids counting permutations.
// Time:      O(n * A)
// Space:     O(A)

#include <iostream>
#include <vector>
using namespace std;

long long count_ways(const vector<int>& coins, int A) {
    vector<long long> dp(A + 1, 0);
    dp[0] = 1;
    for (int c : coins) {
        for (int a = c; a <= A; a++) {
            dp[a] += dp[a - c];
        }
    }
    return dp[A];
}

int main() {
    vector<int> coins = {1, 2, 3};
    cout << "ways to make 4 with {1,2,3} = " << count_ways(coins, 4) << endl;

    coins = {2, 5, 3, 6};
    cout << "ways to make 10 with {2,5,3,6} = " << count_ways(coins, 10) << endl;
    return 0;
}
