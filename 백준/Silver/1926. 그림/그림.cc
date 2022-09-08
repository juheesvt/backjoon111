#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <string>

using namespace std;

vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};

int main() {

    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int r, c;
    cin >> r >> c;

    vector<vector<int>> painting(r, vector<int>(c, 0));
    vector<vector<int>> visited(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> painting[i][j];
        }
    }

    int paintings = 0;
    int maxPaintings = 0;
    queue<pair<int, int>> q;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (visited[i][j] == 0 && painting[i][j] == 1) {
                q.emplace(i, j);
                visited[i][j] = 1;
                paintings++;

                int current = 0;
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    current++;

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (0 <= nx && nx < r && 0 <= ny && ny < c && visited[nx][ny] == 0 && painting[nx][ny] == 1) {
                            q.emplace(nx, ny);
                            visited[nx][ny] = 1;
                        }
                    }
                    if (current > maxPaintings) {
                        maxPaintings = current;
                    }
                }
            }
        }
    }
    cout << paintings << "\n" << maxPaintings;
    return 0;
}
