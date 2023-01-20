#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <stack>
#include <climits>

using namespace std;

const int MOD = 1000000000;

int n, i, j, k, ans;
int dp[101][10][1 << 10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;
    
    int full = (1 << 10) - 1;

    for (j = 1; j <= 9; ++j)
        dp[1][j][1 << j] = 1;

    for (i = 2; i <= n; ++i) {
        for (j = 0; j <= 9; ++j) {
            for (k = 0; k <= full; ++k) {
                if (j == 0)
                    dp[i][0][k | (1 << 0)] = (dp[i][0][k | (1 << 0)] + dp[i - 1][1][k]) % MOD;
                else if (j == 9)
                    dp[i][9][k | (1 << 9)] = (dp[i][9][k | (1 << 9)] + dp[i - 1][8][k]) % MOD;
                else {
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % MOD;
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % MOD;
                }
            }
        }
    }

    for (j = 0; j <= 9; ++j)
        ans = (ans + dp[n][j][full]) % MOD;


    cout << ans;

    return 0;
}