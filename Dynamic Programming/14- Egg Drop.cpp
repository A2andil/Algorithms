// In The Name of Allah

// Egg Drop Problem
//
// Problem:   Given n eggs and a building of k floors, find the minimum number
//            of trials in the worst case needed to determine the highest floor
//            from which an egg can be dropped without breaking.
// Approach:  dp[e][f] = worst-case minimum trials with e eggs and f floors.
//            Recurrence:  dp[e][f] = 1 + min over x in [1..f] of
//                                    max(dp[e-1][x-1], dp[e][f-x])
//            Egg breaks at floor x  → recur on lower floors with e-1 eggs.
//            Egg survives at floor x → recur on upper floors with e eggs.
// Time:      O(n * k^2)
// Space:     O(n * k)

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int egg_drop(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int e = 1; e <= n; e++) {
        dp[e][0] = 0;
        dp[e][1] = 1;
    }
    for (int f = 1; f <= k; f++) dp[1][f] = f;

    for (int e = 2; e <= n; e++) {
        for (int f = 2; f <= k; f++) {
            dp[e][f] = INT_MAX;
            for (int x = 1; x <= f; x++) {
                int worst = 1 + max(dp[e - 1][x - 1], dp[e][f - x]);
                dp[e][f] = min(dp[e][f], worst);
            }
        }
    }
    return dp[n][k];
}

int main() {
    cout << "2 eggs, 10 floors: " << egg_drop(2, 10) << " trials" << endl;
    cout << "2 eggs, 36 floors: " << egg_drop(2, 36) << " trials" << endl;
    cout << "3 eggs, 14 floors: " << egg_drop(3, 14) << " trials" << endl;
    return 0;
}
