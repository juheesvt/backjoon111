#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int search(int size, vector<pair<int, int>> &wall) {
    int x = wall[0].first;
    int cnt = 1;

    for (pair<int, int> pair : wall) {
        // 못가리면 현재 위치 갱신하고 색종이 갯수 하나 추가 !
        if (pair.first >= x + size) {
            x = pair.first;
            cnt++;
        }
    }
    return cnt;
}


int main() {

    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int R, C, paper, wrong;
    cin >> R >> C >> paper >> wrong;

    vector<pair<int, int>> wall;
    int y, x;
    int height = 0;
    for (int i=0; i<wrong; i++) {
        cin >> y >> x;

        // 해당 행에서 제일 큰 y 좌표 갱신 > 색종이 크기가 최소한 y좌표까지는 와야 가릴수잇음
        height = max(height, y);
        // emplace_back() : push_back() 하고 같은 역할인데 더 효율적임
        wall.emplace_back(x, y);
    }

    // x 좌표를 기준으로 정렬
    sort(wall.begin(), wall.end());

    int l = height;
    int r = 1000001;

    int answer = 0;
    while (l<=r) {
        int mid = (l+r) / 2;

        if (search(mid, wall) <= paper) {
            answer = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << answer;

    return 0;
}