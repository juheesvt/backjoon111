#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

const int MAX = 100;
const int INF = 987654321;

int map[MAX][MAX];
int dist[MAX][MAX];

queue<pair<int, int>> pq;

int n, m;

void dijkstra(int r, int c) {
    // 큐에 초기값 푸시
    pq.push({r, c});
    // 초기 거리값 0으로 초기화
    dist[r][c] = 0;

    while (!pq.empty()) {
        int y = pq.front().first;
        int x = pq.front().second;
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (0 <= ny && ny < n && 0 <= nx && nx < m) {
                if (dist[ny][nx] > dist[y][x] + map[ny][nx]) {
                    dist[ny][nx] = dist[y][x] + map[ny][nx];
                    pq.push({ny, nx});
                }
            }
        }
    }
}


int main() {
    cin >> m >> n;

    string tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        for (int j = 0; j < m; j++) {
            map[i][j] = int(tmp[j]) - 48;
            dist[i][j] = INF;
        }
    }

    dijkstra(0, 0);
    cout << dist[n-1][m-1];


    return 0;
}