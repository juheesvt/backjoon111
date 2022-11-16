#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;


int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

const int MAX = 500;
int map[MAX][MAX];
int dp[MAX][MAX];

int n;

int move(int i, int j) {
    if (dp[i][j] != 0)
        return dp[i][j];

    dp[i][j] = 1;

    for (int k=0; k<4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (0 <= ni && ni < n && 0 <= nj && nj < n) {
            if (map[i][j] < map[ni][nj]) {
                dp[i][j] = max(dp[i][j], move(ni, nj) + 1);
            }
        }
    }
    return dp[i][j];
}



int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            answer = max(answer, move(i, j));
        }
    }
    cout << answer;


    return 0;
}