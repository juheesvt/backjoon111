#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <string>
#include <queue>
#include <map>
#include <climits>
#include <stack>


using namespace std;

vector<int> dz = {1, -1, 0, 0, 0, 0};
vector<int> dr = {0, 0, 1, -1, 0, 0};
vector<int> dc = {0, 0, 0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int y, x, h;
    cin >> y >> x >> h;

    vector<vector<vector<int>>> tomatos(h, vector<vector<int>>(x, vector<int>(y, 0)));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < x; j++) {
            for (int k = 0; k < y; k++) {
                cin >> tomatos[i][j][k];
            }
        }
    }

    // 익은 토마토 위치 큐에 넣기 !
    queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < x; j++) {
            for (int k = 0; k < y; k++) {
                if (tomatos[i][j][k] == 1) {
                    q.push({i, {j, k}});
                }
            }
        }
    }

    while (!q.empty()) {
        int z = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();

        // 익은 토마토 주변 6방향 방문
        for (int i = 0; i < 6; i++) {
            int nz = z + dz[i];
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (0 <= nz && nz < h && 0 <= nr && nr < x && 0 <= nc && nc < y) {
                if (tomatos[nz][nr][nc] == 0) {
                    tomatos[nz][nr][nc] = tomatos[z][r][c] + 1;
                    q.push({nz, {nr, nc}});
                }
            }

        }
    }

    int maxVal = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < x; j++) {
            for (int k = 0; k < y; k++) {
                if (tomatos[i][j][k] == 0) {
                    cout << -1;
                    return 0;
                }
                if (tomatos[i][j][k] > maxVal) {
                    maxVal = tomatos[i][j][k];
                }
            }
        }
    }

    cout << maxVal-1;
    return 0;

}


