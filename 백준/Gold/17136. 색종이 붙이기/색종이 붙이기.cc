#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <string>
#include <queue>


using namespace std;

int answer = 26;
vector<int> paper = {0, 0, 0, 0, 0};

int check(vector<vector<int>> &board, int x, int y, int size) {
    for (int i=x; i<x+size+1; i++) {
        for (int j=y; j<y+size+1; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

void solve(vector<vector<int>> &board, int x, int y, int size, int cnt) {

    if (x>=10) {
        answer = min(answer, cnt);
        return;
    }

    if (y>=10) {
        solve(board, x+1, 0, size, cnt);
        return;
    }

    if (board[x][y] == 1) {
        for (int s=0; s<size; s++) {
            if (paper[s]==5) {
                continue;
            }
            if (x+s>=10 || y+s>=10) {
                continue;
            }

            int flag = check(board, x, y, s);

            if (flag==1) {
                for (int i=x; i<x+s+1; i++) {
                    for (int j=y; j<y+s+1; j++) {
                        board[i][j] = 0;
                    }
                }
                paper[s] += 1;
                solve(board, x, y+s+1, size, cnt+1);
                paper[s] -= 1;
                for (int i=x; i<x+s+1; i++) {
                    for (int j=y; j<y+s+1; j++) {
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
    else {
        solve(board, x, y+1, size, cnt);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

   int size = 10;
   vector<vector<int>> board (size, vector<int> (size, 0));

   for (int i=0; i<size; i++) {
       for (int j=0; j<size; j++) {
           cin >> board[i][j];
       }
   }

    solve(board, 0, 0, size/2, 0);
    cout << (answer != 26 ? answer : -1);

    return 0;
}