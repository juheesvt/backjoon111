#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};

int r, c, t;
int map[2][50][50];

int upY, upX, downY, downX;

// 미세 먼지 확산 함수
void spread(int cur) {
    int next = (cur + 1) % 2;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (map[cur][i][j] == -1) {
                map[next][i][j] = -1;
            } else {
                map[next][i][j] = 0;
            }
        }
    }

    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            int val = map[cur][i][j] / 5;
            int candi = 0;
            for (int k=0; k<4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if (ny < r && 0 <= ny && 0 <= nx && nx < c) {
                    if (map[next][ny][nx] != -1) {
                        map[next][ny][nx] += val;
                        candi += val;
                    }
                }
            }
            if (map[next][i][j] != -1) {
                map[next][i][j] += (map[cur][i][j] - candi);
            }
        }
    }
}

void move(int cur) {
    
    for (int i=upY-1; i>0; i--) {
        map[cur][i][0] = map[cur][i-1][0];
    }
    for (int i=0; i<c-1; i++) {
        map[cur][0][i] = map[cur][0][i+1];
    }
    for (int i=0; i<upY; i++) {
        map[cur][i][c-1] = map[cur][i+1][c-1];
    }
    for (int i=c-1; i>1; i--) {
        map[cur][upY][i] = map[cur][upY][i-1];
    }

    map[cur][upY][1] = 0;

    for (int i = downY + 1; i < r; i++) {
        map[cur][i][0] = map[cur][i + 1][0];
    }

    for (int i = 0; i < c - 1; i++) {
        map[cur][r - 1][i] = map[cur][r - 1][i + 1];
    }

    for (int i = r - 1; i > downY; i--) {
        map[cur][i][c - 1] = map[cur][i - 1][c - 1];
    }

    for (int i = c - 1; i > 1; i--) {
        map[cur][downY][i] = map[cur][downY][i - 1];
    }

    map[cur][downY][1] = 0;

}
int main() {

    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    /*
     * 주어진 조건에 맞게 미세먼지 확산시키고 나서
     * 미세먼지를 순환하는 것을 입력받은 시간만큼 반복
     * 50 * 50 * 1000 = 250만 (시뮬레이션 만으로도 가능)
     */

    cin >> r >> c >> t;

    upY = -1;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin >> map[0][i][j];
            if ( map[0][i][j] == -1 ) {
                if (upY == -1) {
                    upY = i, upX = j;
                } else {
                    downY = i, downX = j;
                }
            }
        }
    }

    int cur = 0;
    for (int i=0; i<t; i++) {
        spread(cur);
        cur = (cur+1) % 2;
        move(cur);
    }

    int result = 0;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (map[cur][i][j] != -1) {
                result += map[cur][i][j];
            }
        }
    }
    cout << result;

    return 0;
}