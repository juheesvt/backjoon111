#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int N; // 보석 수
int K; // 가방수

pair<int, int> vJewerly[300001];
int vBag[300000];
priority_queue<int, vector<int>, less<int>> pq;


long long solve() {
    sort(vJewerly, vJewerly + N);
    sort(vBag, vBag + K);

    int idx = 0;
    long long sum = 0;

    for (int i = 0; i < K; i++) {
        while (idx < N && vBag[i] >= vJewerly[idx].first) {
            pq.push(vJewerly[idx].second);
            idx++;
        }
        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> vJewerly[i].first >> vJewerly[i].second;
    }
    for (int i = 0; i < K; ++i) {
        cin >> vBag[i];
    }
    cout << solve();
}