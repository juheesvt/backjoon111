#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 1000;

int n, m, k;
int map[MAX][MAX];
int visited[MAX][MAX][10];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

struct Item {
    int x, y, curK;
};

int bfs(int sx, int sy) {
    // x, y, k
    queue<Item> q;
    q.push({sx, sy, 0});

    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int curK = q.front().curK;
        q.pop();

        if (x == n-1 && y == m-1)
            return visited[x][y][curK] + 1;

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            // TODO: 시간 초과 해결 -> https://www.acmicpc.net/board/view/93863
            if (visited[nx][ny][curK] == 0) {
                // 갈수 있는 길, 뚫은 상태 or 안뚫은상태 쭉감
                if (map[nx][ny] == 0) {
                    q.push({nx, ny, curK});
                    visited[nx][ny][curK] = visited[x][y][curK] + 1;
                } else if (curK < k) {             // 못가는데 뚫을 수 있으면
                    q.push({nx, ny, curK + 1});
                    visited[nx][ny][curK + 1] = visited[x][y][curK] + 1;
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    string rows;
    for (int i=0; i<n; i++) {
        cin >> rows;
        for (int j=0; j<m; j++) {
            map[i][j] = rows[j] - 48;
        }
    }
    memset(visited, 0, sizeof(visited));

    cout << bfs(0, 0);
    return 0;
}