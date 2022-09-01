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

vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {1, -1, 0, 0};
vector<vector<int>> visited;
vector<vector<int>> country;

vector<pair<int, int>> bfs(int n, int l, int r, int i, int j) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> tmp;

    q.emplace(i, j);
    tmp.emplace_back(i, j);

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        visited[x][y] = 1;

        q.pop();
        for (int k = 0; k < 4; k++) {

            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny]) {
                int gap = abs(country[nx][ny] - country[x][y]);
                if (l <= gap && gap <= r) {
                    visited[nx][ny] = 1;
                    q.emplace(nx, ny);
                    tmp.emplace_back(nx, ny);
                }
            }
        }
    }
    return tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int flag;
    int n, l, r;
    cin >> n >> l >> r;

    country.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> country[i][j];
        }
    }

    int day = 0;
    while (1) {
        visited.resize(n, vector<int>(n, 0));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                visited[i][j] = 0;
            }
        }
        flag = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 0) {
                    visited[i][j] = 1;
                    vector<pair<int, int>> uni = bfs(n, l, r, i, j);

                    // 국경선이 모두 열렸으면 인구이동 시작
                    if (uni.size() > 1) {
                        flag = 1;
                        int sum = 0;
                        for (auto &pair: uni) {
                            sum += country[pair.first][pair.second];
                        }
                        for (auto &pair: uni) {
                            country[pair.first][pair.second] = int(sum / uni.size());
                        }

                    }
                }
            }
        }
        if (flag == 0)
            break;
        day += 1;
    }
    cout << day;


    return 0;
}
