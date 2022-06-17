//
// Created by 강주희 on 2022/06/18.
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> dy = {1, -1, 0, 0};
vector<int> dx = {0, 0, 1, -1};

int maxVal = 0;

int cntZero(vector<vector<int>> mapp, int n, int m) {
    int cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mapp[i][j] == 0) {
                cnt++;
            }
        }
    }
    return cnt;
}

void bfs(vector<vector<int>> mapp, int n, int m) {

    vector<vector<int>> queue;

    // 바이러스의 위치를 큐에 집어넣기
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mapp[i][j] == 2) {
                queue.push_back({i,j});
            }
        }
    }

    // bfs 이용해서
    while(queue.size()) {
        int y = queue[0][0];
        int x = queue[0][1];
        queue.erase(queue.begin());

        for (int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if ( 0<=ny && ny<n && 0<=nx && nx<m ) {
                if (mapp[ny][nx] == 0) {
                    mapp[ny][nx] = 2;
                    queue.push_back({ny, nx});
                }
            }
        }
    }
    maxVal = max(maxVal, cntZero(mapp, n, m));

}

void buildWall(vector<vector<int>> mapp, int walls, int n, int m){
    if (walls == 3) {
        bfs(mapp, n, m);
        return;
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mapp[i][j] == 0) {
                mapp[i][j] = 1;
                buildWall(mapp, walls+1, n, m);
                mapp[i][j] = 0;                         // 새로운 조합을 찾기 위해 지은 벽을 돌려주는 과정
            }
        }
    }

}

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> mapp (n, vector<int> (m,0));

    for (int i =0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> mapp[i][j];
        }
    }
    buildWall(mapp, 0, n, m);
    cout << maxVal;
    return 0;
}