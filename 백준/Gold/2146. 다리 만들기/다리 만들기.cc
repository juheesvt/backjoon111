#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
#include <memory.h>

using namespace std;
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

const int MAX = 100;
int map[MAX][MAX];
int visited[MAX][MAX];

int island = 1;
int answer = INT_MAX;
int n;

void islandBfs(int i, int j) {
    queue<pair<int, int>> q;
    visited[i][j] = 1;
    map[i][j] = island;
    q.emplace(i, j);

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny]) {
                if (map[nx][ny] == 1) {
                    q.emplace(nx, ny);
                    visited[nx][ny] = 1;
                    map[nx][ny] = island;
                }
            }
        }
    }
}

int bridgeBfs(int num) {
    // x, y, 다리 길이
    queue<pair<int, pair<int, int>>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == num) {
                q.emplace(i, make_pair(j, 0));
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second.first;
        int b = q. front().second.second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                if (map[nx][ny] != 0 && map[nx][ny] != num) {
                    return b;
                }
                // 0 으로 되어있는 바다만 건너기
                if (map[nx][ny] == 0 && !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    q.emplace(nx, make_pair(ny, b+1));
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    // 1. input
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    // 2. 섬 구분하기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                islandBfs(i, j);
                island++;
            }
        }
    }

    for (int i = 1; i < island; i++) {
        answer = min(answer, bridgeBfs(i));
        memset(visited, 0, sizeof(visited));
    }
    cout << answer;


    return 0;
}