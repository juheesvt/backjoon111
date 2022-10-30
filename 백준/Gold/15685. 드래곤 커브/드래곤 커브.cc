#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

/*
 * 한 세대의 방향정보를 역순으로 탐색하면서 +1 을 시켜준 값이 그 다음 세대의 방향정보
 * 0세대 : 0
 * 1세대 : 0 1
 * 2세대 : 0 1 2 1
 * 3세대 : 0 1 2 1 2 3 2 1
 * 다음 세대의 추가되는 선분의 방향정보 = 이전 세대의 방향정보를 역순으로 탐색하면서 + 1 % 4 를 한 것
 *
 */

const int MAX = 101;
int N, x, y, d, g;
int MAP[MAX][MAX];

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1,0};

vector<int> dirInfo;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> y >> x >> d >> g;
        dirInfo.clear();

        MAP[x][y] = 1;
        x += dx[d];
        y += dy[d];
        MAP[x][y] = 1;

        dirInfo.push_back(d);
        for (int j = 0; j < g; j++) {
            // 드래곤 커브 만들기
            int s = dirInfo.size(); // 몇 세대인지
            for (int k = s - 1; k >= 0; k--) {
                int nd = (dirInfo[k] + 1) % 4;
                x += dx[nd];
                y += dy[nd];
                MAP[x][y] = 1;

                dirInfo.push_back(nd);
            }
        }
    }
    // 사각형 갯수
    int cnt = 0;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            //인접한 4칸의 정사각형이 모두 드래곤의 일부이면
            if (MAP[i][j] == 1 && MAP[i + 1][j] == 1 && MAP[i][j + 1] == 1 && MAP[i + 1][j + 1] == true) {
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
}