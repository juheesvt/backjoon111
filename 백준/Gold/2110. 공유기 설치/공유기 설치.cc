#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <queue>

using namespace std;

int isInstall(vector<int> &home, int distance, int c) {
    int current = home[0];
    int cnt = 1;
    for (int i=1; i<home.size(); i++) {
        if (current+distance <= home[i]) {
            cnt++;
            current = home[i];
        }
    }
    if (cnt >= c)   return 1;
    return 0;
}


int main() {

    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n, c;
    cin >> n >> c;

    vector<int> home (n, 0);
    for (int i=0; i<n; i++) {
        cin >> home[i];
    }
    sort(home.begin(), home.end());

    /*
     * 파라메트릭 서치 : 최적화 문제 -> 결정 문제
     *
     * (최적화문제) 가장 인접한 공유기 사이의 최대 거리는 ?
     * (결정문제) 가장 인접한 공유기 사이의 거리가 x 일 때, 공유기를 모두 설치 할 수 있나 ?
     *
     * --> 공유기를 모두 설치 못하면 거리 좁히기
     * --> 공유기를 모두 설치 할 수 있으면 거리 늘리기
     */

    int start = 0;
    int end = home[home.size()-1] - home[0];

    int mid;
    while (start <= end) {
        mid = (start+end)/2;

        if (isInstall(home, mid, c)) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    cout << end;
    return 0;
}