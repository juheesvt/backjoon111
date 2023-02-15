#include <algorithm>
#include <iostream>
#include <climits>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 130;

int n;
vector<vector<int>> rupee;
vector<vector<int>> map;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};


void dijkstra() {

    rupee = vector<vector<int>> (MAX, vector<int> (MAX, INT_MAX));
    priority_queue<pair<int, pair<int, int>>> pq;

    // 기본 pq는 내림차 순으로 되어있음. rupee를 최대한 적게 얻어야하기 때문에 - 부호를 붙여서 삽입하기
    pq.push(make_pair(-map[0][0], make_pair(0, 0)));
    rupee[0][0] = map[0][0];

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (cost != rupee[x][y]) continue;

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 > nx || nx >= n || ny < 0 || ny >= n) continue;

            // 거쳐가는 것이 더 작을 경우
            if (cost + map[nx][ny] < rupee[nx][ny]) {
                rupee[nx][ny] = cost + map[nx][ny];
                pq.push(make_pair(-rupee[nx][ny], make_pair(nx, ny)));
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    while (true) {
        cin >> n;
        if (n == 0) break;

        map = vector<vector<int>> (MAX, vector<int> (MAX, INT_MAX));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> map[i][j];
            }
        }
        dijkstra();
        cout << "Problem " << t << ": " << rupee[n-1][n-1] << "\n";
        t++;
    }
    return 0;
}