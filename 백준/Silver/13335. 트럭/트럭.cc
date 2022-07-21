#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <queue>

using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n, w, l;
    cin >> n >> w >> l;

    vector<int> trucks (n, 0);
    for (int i=0; i<n; i++) {
        cin >> trucks[i];
    }

    vector<pair<int, int>> bridge;      // {트럭의 무게, 다리에서 소요된 시간}
    int brigeWeight = 0;

    int time = 0;
    int truckIdx = 0;           // 출발 예정인 트럭의 인덱스
    int endTruck = 0;           // 다리를 건넌 트럭의 갯수
    do {
        // 현재 다리에 걸린 하중 + 출발 예정인 트럭의 하중 <= 다리가 버틸 수 있는 하중
        if (brigeWeight + trucks[truckIdx] <= l) {
            brigeWeight += trucks[truckIdx];
            bridge.emplace_back(trucks[truckIdx], 0);
            truckIdx++;
        }

        for (int i=0; i<bridge.size(); i++) {
            bridge[i].second++;
        }

        if (bridge[0].second == w) {
            brigeWeight -= bridge[0].first;
            bridge.erase(bridge.begin());
            endTruck++;
        }
        time++;
    }
    while (endTruck < n);

    cout << time+1;

    return 0;
}