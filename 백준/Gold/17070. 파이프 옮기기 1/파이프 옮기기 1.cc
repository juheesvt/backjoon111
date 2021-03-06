#include <iostream>
#include <vector>

using namespace std;

int main() {

    const int ROW = 0;
    const int COL = 1;
    const int DIG = 2;

    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> map(n, vector<int>(n, 0));
    vector<vector<vector<int>>> dp(3, vector<vector<int>>(n, vector<int>(n, 0)));
    // {{{}*n},{{}*n},{{}*n}}
    // 가로, 세로, 대각선

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    /*
     * dp[]     : 가로 || 세로 || 대각선
     * dp[][]   : 행
     * dp[][][] : 좌표 하나
     */

    dp[0][0][1] = 1;

    // 첫 행 초기화 : 첫 행은 왼쪽 가로방향에서만 올 수 있으므로, 가로방향에 해당하는 dp 자리만 초기화
    for (int i = 2; i < n; i++) {
        if (map[0][i] == 0) {
            dp[0][0][i] = dp[0][0][i - 1];
        }
    }

    /*
     * [ ] [ ]
     * [ ] [O]
     */
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (map[i][j] == 0 && map[i][j - 1] == 0 && map[i - 1][j] == 0) {
                //               ㅡ  \                | \                               \ \   ;
                dp[DIG][i][j] = dp[ROW][i - 1][j - 1] + dp[COL][i - 1][j - 1] + dp[DIG][i - 1][j - 1];
            }

            if (map[i][j] == 0) {
                //                ㅡ ㅡ                 \ ㅡ
                dp[ROW][i][j] = dp[ROW][i][j - 1] + dp[DIG][i][j - 1];
                //                 | |
                dp[COL][i][j] = dp[COL][i - 1][j] + dp[DIG][i - 1][j];
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += dp[i][n - 1][n - 1];
    }
    cout << sum;

    return 0;
}