//in the name of God

#include <iostream>
#include <algorithm>

#define ll long long
#define N 5
using namespace std;

const int sz = 1000;
int dp[sz][sz];

int pathGrid(int x, int y, int list[N][N]) {
        for (int i = 0; i < N + 1; i++) {
                for (int j = 0; j < N + 1; j++) {
                        if (!j || !i) dp[i][j] = 0;
                        else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + list[i - 1][j - 1];
                }
        }
        return dp[x][y];
}

int main(){
        ios::sync_with_stdio(0), cin.tie();
        int list[5][5] = {
                { 3, 7, 9, 2, 7 },
                { 9, 8, 3, 5, 5 },
                { 1, 7, 9, 8, 5 },
                { 3, 8, 6, 4, 9 },
                { 6, 3, 9, 7, 8 }
        };
        cout << pathGrid(5, 5, list) << endl;
        return 0;
}
