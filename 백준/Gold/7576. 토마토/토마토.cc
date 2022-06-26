#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {-1, 1, 0, 0};



int main() {

    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);


    int n, m;
    cin >> m >> n;

    vector<vector<int>> tomatos (n, vector<int>(m, 0));

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++){
            cin >> tomatos[i][j];
        }
    }

    // 익은 토마토가 있는 지점 큐에 넣기
    queue<pair<int, int>> q;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++){
            if (tomatos[i][j] == 1) {
                q.push(make_pair(i, j));
            }
        }
    }

    while (!q.empty()) {

        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 익은 토마토의 상하 좌우 방문
            if (0<=nx && nx<n && 0<=ny && ny<m) {
                // 다음 지점에 익지 않은 토마토가 존재하면
                if (tomatos[nx][ny] == 0) {
                    tomatos[nx][ny] = tomatos[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    int max = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (tomatos[i][j] == 0) {
                cout << -1;
                return 0;
            }
            if (tomatos[i][j] > max) {
                max = tomatos[i][j];
            }
        }
    } 
    cout << max-1;
    return 0;

}