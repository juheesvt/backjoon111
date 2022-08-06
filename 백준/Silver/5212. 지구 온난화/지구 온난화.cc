#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <string>

using namespace std;

vector<int> dy = {-1, 1, 0, 0};
vector<int> dx = {0, 0, 1, -1};

int main() {

    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int r, c;
    cin >> r >> c;

    vector<vector<int>> mapp (r+2, vector<int> (c+2, 0));
    for (int i=1; i<r+1; i++) {
        string tmp;
        cin >> tmp;
        for (int j=1; j<c+1; j++) {
            mapp[i][j] = tmp[j-1];
        }
    }

    // 바깥 패딩 .으로 채워주기
    for (int i=0; i<c+2; i++) {
        mapp[0][i] = '.';
        mapp[r+1][i] = '.';
    }

    for (int i=0; i<r+2; i++) {
        mapp[i][0] = '.';
        mapp[i][c+1] = '.';
    }


    for (int i=0; i<r+2; i++) {
         for (int j=0; j<c+2; j++) {
             if (mapp[i][j] == 'X') {
                 int cnt = 0;
                 for (int k=0; k<4; k++) {
                     int nr = i + dx[k];
                     int nc = j + dy[k];

                     if (0 <= nr && nr < r + 2 && 0 <= nc && nc < c + 2)
                         if (mapp[nr][nc] == '.')
                             cnt++;


                 }
                     if (cnt>=3)
                         mapp[i][j] = '-';
             }
         }
     }

    pair<int, int> start = {r+2, c+2};
    pair<int, int> end = {0, 0};
    for (int i=0; i<r+2; i++) {
        for (int j=0; j<c+2; j++) {
            if (mapp[i][j]=='X') {
                start.first = min(start.first, i);
                start.second = min(start.second, j);
                end.first = max(end.first, i);
                end.second = max(end.second, j);
            }
        }
    }

    for (int i=start.first; i<end.first+1; i++) {
        for (int j=start.second; j<end.second+1; j++) {
            if (mapp[i][j]!='X')    cout << '.';
            else                    cout << 'X';
        }
        cout << "\n";
    }

    return 0;
}