#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
#include <set>

using namespace std;

const int MAX = 10;

int board[MAX][MAX];
int getAnswer = 0;

// 3 by 3 box, row, col 숫자들을 저장할 set
unordered_set<int> bigbox[3][3];
unordered_set<int> rowline[9];
unordered_set<int> colline[9];

void dfs(vector<pair<int, int>> &blanks, int pos) {
    if (getAnswer == 1)
        return;

    if (pos == blanks.size()) {
        getAnswer = 1;

        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }

    int nowRow = blanks[pos].first;
    int nowCol = blanks[pos].second;

    for (int i=1; i<=9; i++) {
        if (bigbox[nowRow/3][nowCol/3].count(i) == 0 &&
            rowline[nowRow].count(i) == 0 && colline[nowCol].count(i) == 0) {

            bigbox[nowRow / 3][nowCol / 3].insert(i);
            rowline[nowRow].insert(i);
            colline[nowCol].insert(i);
            board[nowRow][nowCol] = i;

            dfs(blanks, pos + 1);

            bigbox[nowRow / 3][nowCol / 3].erase(i);
            rowline[nowRow].erase(i);
            colline[nowCol].erase(i);
            board[nowRow][nowCol] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    vector<pair<int, int>> blanks;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int num; cin >> num;
            if (num == 0) blanks.emplace_back( i,j );
            else {
                bigbox[i / 3][j / 3].insert(num);
                rowline[i].insert(num);
                colline[j].insert(num);
            }
            board[i][j] = num;
        }
    }

    dfs(blanks, 0);





    return 0;
}