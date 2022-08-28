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

vector<vector<pair<int, int>>> tetrominos = {{{0, 0}, {0, 1}, {0, 2}, {0, 3}},      // 1번
                                             {{0, 0}, {1, 0}, {2, 0}, {3, 0}},

                                             {{0, 0}, {0, 1}, {1, 0}, {1, 1}},      // 2번

                                             {{0, 0}, {1, 0}, {2, 0}, {2, 1}},      // 3번
                                             {{0, 1}, {1, 1}, {2, 1}, {2, 0}},     // 3번 대칭
                                             
                                             {{0, 0}, {0, 1}, {0, 2}, {1, 0}},      // 3번 90도
                                             {{0, 0}, {0, 1}, {1, 1}, {2, 1}},      // 3번 180도
                                             {{0, 0}, {0, 1}, {0, 2}, {-1, 2}},      // 3번 270도
                                             
                                             {{0, 0}, {1, 0}, {1, 1}, {1, 2}},      // 3번 90도
                                             {{0, 0}, {0, 1}, {1, 0}, {2, 0}},      // 3번 180도
                                             {{0, 0}, {0, 1}, {0, 2}, {1, 2}},      // 3번 270도

                                             {{0, 0}, {1, 0}, {1, 1}, {2, 1}},      // 4번
                                             {{0, 0}, {1, 0}, {1, -1}, {2, -1}},     // 4번 대칭
                                             {{0, 0}, {0, 1}, {-1, 1}, {-1, 2}},      // 4번 90도
                                             {{0, 0}, {0, 1}, {1, 1}, {1, 2}},

                                             {{0, 0}, {0, 1}, {0, 2}, {1, 1}},      // 5번
                                             {{0, 0}, {0, 1}, {0, 2}, {-1, 1}},      // 5번 대칭
                                             {{0, 0}, {1, 0}, {2, 0}, {1, -1}},      // 5번 90도
                                             {{0, 0}, {1, 0}, {2, 0}, {1, 1}}};      // 5번 90도

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);


    int r, c;
    cin >> r >> c;

    vector<vector<int>> mapp (r, vector<int> (c, 0));
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin >> mapp[i][j];
        }
    }

    int max = INT_MIN;

    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            for (auto &tetromino : tetrominos) {
                int sum = 0;
                int complete = 1;
                for (auto &coor : tetromino) {
                    if (0 <= i+coor.first && i+coor.first < r && j+coor.second < c && 0 <= j+coor.second) {
                        sum += mapp[i+coor.first][j+coor.second];
                    } else {
                        complete = 0;
                        break;
                    }
                }
                if (complete && max < sum) {
                    max = sum;
                }
            }
        }
    }

    cout << max;
    return 0;
}
