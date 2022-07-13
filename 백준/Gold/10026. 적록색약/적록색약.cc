#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0 ,0, -1, 1};

int bfs(int n, int i, int j, vector<vector<char>> &mapp, vector<vector<int>> &visited) {

    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = 1;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k=0; k<4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx>=0 && ny>=0 && nx<n && ny<n && !visited[nx][ny]) {
                if (mapp[x][y] == mapp[nx][ny]) {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    return 1;
}

int main() {

    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<char>> mapp (n, vector<char> (n, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> mapp[i][j];
        }
    }

    int a = 0;
    vector<vector<int>> visited (n, vector<int> (n, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (!visited[i][j]) {
                a += bfs(n, i, j, mapp, visited);
            }
        }
    }

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (mapp[i][j] == 'G')
                mapp[i][j] = 'R';



    int b = 0;
    vector<vector<int>> visited2 (n, vector<int> (n, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (!visited2[i][j]) {
                b += bfs(n, i, j, mapp, visited2);
            }
        }
    }
    cout << a << " " << b;
    return 0;
}