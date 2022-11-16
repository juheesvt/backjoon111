#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;


int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

const int MAX = 300;
const int INF = 987654321;

int map[MAX][MAX];
int map2[MAX][MAX];
int visited[MAX][MAX];

queue<pair<int, int>> pq;

int n, m;

int bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = 1;

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nr = cr + dx[k];
            int nc = cc + dy[k];

            if (0 <= nr && nr < n && 0 <= nc && nc < m && !visited[nr][nc] && map[nr][nc] > 0) {
                q.push({nr, nc});
                visited[nr][nc] = 1;
            }
        }
    }
    return 1;
}


int main() {
    cin >> n >> m;
    int answer = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    while (1) {

        // 맞닿은 바다 칸 수 세서 map2에 저장
        memset(map2, 0, sizeof(map2));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int nr = i + dx[k];
                    int nc = j + dy[k];
                    if (0 <= nr && nr < n && 0 <= nc && nc < m) {
                        if (map[nr][nc] == 0) {
                            cnt++;
                        }
                    }
                }
                map2[i][j] = cnt;
            }
        }
        // 빙하 녹이기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                map[i][j] -= map2[i][j];
                if (map[i][j] < 0)  map[i][j] = 0;
            }
        }
        answer++;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += map[i][j];    
            }
        }
        if (sum == 0) {
            cout << 0;
            return 0;
        }

        // 빙하 분리되었는지 검사
        int island = 0;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] > 0 && !visited[i][j]) {
                    island += bfs(i, j);
                }
            }
        }
        if (island > 1)        break;
    }
    cout << answer;

    return 0;
}