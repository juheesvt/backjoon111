#include <iostream>
#include <string>
#include <queue>
using namespace std;

#define MX 1001

typedef struct Pos {
    int x, y, breakCount, cost;

    Pos(int _x, int _y, int _breakCount, int _cost) : x(_x), y(_y), breakCount(_breakCount), cost(_cost) {}
}Pos;
int n, m, k, board[MX][MX], breakCount[MX][MX];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

bool isInRange(int x, int y) {
    return x > 0 && x <= n && y > 0 && y <= m;
}
int bfs() {
    queue<Pos> q;
    q.push(Pos(1, 1, 0, 1));
    breakCount[1][1] = 0;

    while(!q.empty()) {
        Pos now = q.front();
        q.pop();

        if(now.x == n && now.y == m)
            return now.cost;

        for(int i = 0; i < 4; ++i) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if(!isInRange(nx, ny)) continue;
            if(breakCount[nx][ny] <= now.breakCount) continue;

            if(board[nx][ny]) {
                if(now.breakCount >= k) continue;

                // cost 가 짝수일 경우: 밤
                if(now.cost % 2 == 0) {
                    q.push(Pos(now.x, now.y, now.breakCount, now.cost + 1));
                }
                else {
                    breakCount[nx][ny] = now.breakCount;
                    //breakCount[nx][ny] = now.breakCount + 1;
                    q.push(Pos(nx, ny, now.breakCount + 1, now.cost + 1));
                }
            }
            else if(!board[nx][ny]) {
                breakCount[nx][ny] = now.breakCount;
                q.push(Pos(nx, ny, now.breakCount, now.cost + 1));
            }
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m >> k;

    char input;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> input;
            board[i][j] = input - '0';
            breakCount[i][j] = k + 1;
        }
    }
    cout << bfs();
}