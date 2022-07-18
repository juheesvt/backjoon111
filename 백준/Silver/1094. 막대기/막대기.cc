#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int sum (vector<int> &sticks) {
    int sum = 0;
    for (int i=0; i<sticks.size()-1; i++) {
        sum += sticks[i];
    }
    return sum;
}
int main() {

    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int x;
    cin >> x;

    if (x == 64) {
        cout << 1;
        return 0;
    };

    vector<int> sticks;
    sticks.push_back(64);

    int idx = 0;
    while (1) {

        if (sum(sticks) == x)   break;

        // 1. 가지고 있는 막대기 중 가장 짧은 막대기 반으로 자르기
        sticks[idx] >>= 1;
        if (idx <= sticks.size()) {
            sticks.push_back(sticks[idx]);          // 자른 막대기 나머지 반 벡터에 추가
        }
        if (sum(sticks) > x) {                   // 자른 막대기의 절반 중 하나 버리고 남은 모든 막대 더한게 x 보다 크거나 같으면,
            sticks.pop_back();                         // 절반 막대기 하나 버리기;
            continue;
        }
        idx++;
    }
    cout << sticks.size()-1;

    return 0;
}