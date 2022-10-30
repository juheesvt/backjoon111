#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

/*
 * 갯수가 작은 놈이 앞에오고 그 놈이 여러개라면 숫자가 작은것이 더 앞에 오게 된다.
 */
const int MAX = 101;

int R, C, K, answer;
int MAP[MAX][MAX];
int numCnt[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> K;
    for (int i=1; i<=3; i++) {
        for (int j=1; j<=3; j++) {
            cin >> MAP[i][j];
        }
    }

    if (MAP[R][C] == K) {
        answer = 0;
        cout << answer << "\n";
        return 0;
    }

    int time = 0;
    int r = 3, c = 3;
    while (1) {
        if (MAP[R][C] == K) {
            answer = time;
            break;
        }
        if (time > 100) {
            answer = -1;
            break;
        }

        vector<int> size;
        if (r >= c) {// 정사각형 or 세로로 긴 형태
            for (int i=1; i<=r; i++) {
                vector<pair<int, int>> v;
                memset(numCnt, 0, sizeof(numCnt));
                for (int j=1; j<=c; j++) {
                    numCnt[MAP[i][j]]++;    // 숫자 갯수 증가 시키기
                }
                for (int j=1; j<MAX; j++) {
                    if (numCnt[j] == 0) continue;
                    v.push_back({numCnt[j], j});    // (갯수, 숫자) -> 정렬을 위해
                }
                sort(v.begin(), v.end());

                for (int j=1; j<=c; j++) {
                    MAP[i][j] = 0;
                }
                int idx = 1;
                for (int j=0; j<v.size(); j++) {
                    MAP[i][idx++] = v[j].second;    // 숫자
                    MAP[i][idx++] = v[j].first;     // 숫자의 갯수
                }
                idx--;
                size.push_back(idx);
            }
            sort(size.begin(), size.end());
            c = size.back();
        } else {
            for (int i=1; i<=c; i++) {
                vector<pair<int, int>> v;
                memset(numCnt, 0, sizeof(numCnt));
                for (int j=1; j<=r; j++) {
                    numCnt[MAP[j][i]]++;    // 숫자 갯수 증가 시키기
                }
                for (int j=1; j<MAX; j++) {
                    if (numCnt[j] != 0) {
                        v.push_back({numCnt[j], j});    // (갯수, 숫자) -> 정렬을 위해
                    }
                }
                sort(v.begin(), v.end());

                for (int j=1; j<=r; j++) {
                    MAP[j][i] = 0;
                }
                int idx = 1;
                for (int j=0; j<v.size(); j++) {
                    MAP[idx++][i] = v[j].second;    // 숫자
                    MAP[idx++][i] = v[j].first;     // 숫자의 갯수
                }
                idx--;
                size.push_back(idx);
            }
            sort(size.begin(), size.end());
            r = size.back();
        }
        time++;
    }

    cout << answer;

}