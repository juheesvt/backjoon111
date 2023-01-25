#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 1000;
const int INF = 987654321;

int n, m, k;
int answer = -1;

int map[MAX][MAX];
int visited[MAX][MAX][2];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int bfs(int sx, int sy, int k) {
    // x, y, k
    queue<vector<int>> q;
    q.push({sx, sy, 0});

    while(!q.empty()) {
        int x = q.front()[0];
        int y = q.front()[1];
        int curK = q.front()[2];
        q.pop();

        if (x == n-1 && y == m-1)
            return visited[x][y][curK] + 1;

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            // TODO: K 탐색 어떻게 할건지 ?
            if (visited[nx][ny][curK] == 0) {
                // 갈수 있는 길, 뚫은 상태 or 안뚫은상태 쭉감
                if (map[nx][ny] == 0) {
                    q.push({nx, ny, curK});
                    visited[nx][ny][curK] = visited[x][y][curK] + 1;
                } else if (curK == 0) {             // 못가는데 뚫을 수 있으면
                    q.push({nx, ny, 1 - curK});
                    visited[nx][ny][1-curK] = visited[x][y][curK] + 1;
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

    cin >> n >> m;
    string rows;
    for (int i=0; i<n; i++) {
        cin >> rows;
        for (int j=0; j<m; j++) {
            map[i][j] = rows[j] - 48;
        }
    }
    memset(visited, 0, sizeof(visited));

    cout << bfs(0, 0, 0);
    return 0;
}