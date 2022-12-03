#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 50;
int map[MAX][MAX];

int r1, c1, r2, c2, m=0, s=0;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> r1 >> c1 >> r2 >> c2;
    for (int i=r1; i<=r2; i++) {
        for (int j=c1; j<=c2; j++) {
            int x = i - r1;
            int y = j - c1;
            if (i-j < 0) { // 왼쪽
                if (i + j < 0) {
                    map[x][y] = 4*i*i + i + 1 - j;
                } else {
                    map[x][y] = 4*j*j - 3*j + 1 - i;
                }
            } else {
                if (i+j < 0) {
                    map[x][y] = 4*j*j - j + 1 + i;
                } else {
                    map[x][y] = 4*i*i + 3*i + 1 + j;
                }
            }
            if (map[x][y] > m) {
                m = map[x][y];
            }
        }
    }
    for (; m; m /= 10) s++;
    for (int i=0; i <= r2-r1; i++) {
        for (int j=0; j <= c2 - c1; j++) {
            printf("%*d ", s, map[i][j]);
        }
        printf("\n");
    }
    return 0;
}