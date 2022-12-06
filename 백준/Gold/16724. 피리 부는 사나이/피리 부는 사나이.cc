#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1000;
int map[MAX][MAX];
int visit[MAX][MAX];

int n, m, answer;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs (int x, int y) {
    visit[x][y] = 1;
    int nx = x + dx[map[x][y]];
    int ny = y + dy[map[x][y]];

    if (visit[nx][ny] == 1)     answer++;
    if (visit[nx][ny] == 0)     dfs(nx, ny);

    // 이미 쉼터에 갈 수 있는 노드
    visit[x][y] = 2;

}
// 사이클 찾는 문제
int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            char c;
            cin >> c;
            if (c == 'U') {
                map[i][j] = 1;
            } else if (c == 'R') {
                map[i][j] = 2;
            } else if (c == 'L') {
                map[i][j] = 3;
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (visit[i][j] == 0) {
                dfs(i, j);
            }
        }
    }

    cout << answer;

}