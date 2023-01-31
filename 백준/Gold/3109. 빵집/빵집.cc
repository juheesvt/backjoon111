#include <iostream>
#include <cstring>
#include <queue>

using namespace std;


int n, m;
int answer = 0;
string map[10000];
int visited[10000][500];

// 오른쪽 위 대각선, 오른쪽, 오른쪽 아래 대각선
int dx[] = {-1, 0, 1};
int dy[] = {1, 1, 1};

int dfs(int x, int y) {

    visited[x][y] = 1;
    if (y == m-1) {
        answer++;
        return 1;
    }

    for (int i=0; i<3; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (visited[nx][ny] || map[nx][ny] == 'x') continue;


        if (dfs(nx, ny))
            return 1;

    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
            cin >> map[i];
    }
    memset(visited, 0, sizeof(visited));
    for (int i=0; i<n; i++) {
        dfs(i, 0);
    }
    cout << answer;

    return 0;
}