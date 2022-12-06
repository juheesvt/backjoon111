#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 101;
int weight[MAX];
int value[MAX];
int dp[MAX][100001];
int n, k;


int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> weight[i] >> value[i];
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=k; j++) {
            if (j >= weight[i]) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][k];

}