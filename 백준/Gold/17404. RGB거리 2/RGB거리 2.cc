#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10000001;
const int R = 0;
const int G = 1;
const int B = 2;

int cache[1001][3];




int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    /*
        1. 1번집이 R이고 마지막집이 R일때 최소비용

        2. 1번집이 R이고 마지막집이 G일때 최소비용

        3. 1번집이 R이고 마지막집이 B일때 최소비용

        4. 1번집이 G이고 마지막집이 R일때 최소비용

        5. 1번집이 G이고 마지막집이 G일때 최소비용

        6. 1번집이 G이고 마지막집이 B일때 최소비용

        7. 1번집이 B이고 마지막집이 R일때 최소비용

        8. 1번집이 B이고 마지막집이 G일때 최소비용

        9. 1번집이 B이고 마지막집이 B일때 최소비용
        
        1, 5, 9번을 제외한 나머지 중에서 최소값을 찾으면 답
     */


    int n, r, g, b;
    int answer = MAX;

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> r >> g >> b;
        cache[i][R] = r;
        cache[i][G] = g;
        cache[i][B] = b;
    }

    for (int start=0; start <=2; start++) {
        int dp[1001][3];
        for (int j=0; j<=2; j++) {
            if (j == start) {
                dp[1][start] = cache[1][start];
            } else {
                dp[1][j] = MAX;
            }
        }
        for (int i=2; i<=n; i++) {
            dp[i][R] = min(dp[i-1][1], dp[i-1][2]) + cache[i][R];
            dp[i][G] = min(dp[i-1][0], dp[i-1][2]) + cache[i][G];
            dp[i][B] = min(dp[i-1][1], dp[i-1][0]) + cache[i][B];
        }
        for (int j=0; j<=2; j++) {
            if (j == start)
                continue;
            answer = min(answer, dp[n][j]);
        }
    }
    cout << answer;

    return 0;
}