#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <stack>
#include <climits>

using namespace std;

const int MAX = 16;
const int INF = 987654321;
int map[MAX][MAX];
int dp[MAX][1 << MAX];

int n, endBit;

int dfs(int curNode, int curBit) {
    if (curBit == endBit)
        return map[curNode][0] == 0 ? INF : map[curNode][0];

    if (dp[curNode][curBit] != -1)      return dp[curNode][curBit];
    dp[curNode][curBit] = INF;

    for (int i=0; i<n; i++) {
        if (map[curNode][i] == 0)            continue;
        if ((curBit & (1 << i)) == (1 << i)) continue;

        dp[curNode][curBit] = min(dp[curNode][curBit], map[curNode][i] + dfs(i, curBit | 1 << i));
    }
    return dp[curNode][curBit];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> map[i][j];
        }
    }
    endBit = (1 << n) - 1;

    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 1);




    return 0;
}