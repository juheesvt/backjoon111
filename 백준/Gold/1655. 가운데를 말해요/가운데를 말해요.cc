#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int t;
    cin >> t;
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;

    while (t--) {
        int a;
        cin >> a;

        if (max.size() == min.size()) {
            max.push(a);
        } else {
            min.push(a);
        }

        // 두 큐가 비어있지않고, 작은 것 중에 큰 값이 큰 것들 중에 작은 값보다 크다면 swap
        if (!max.empty() && !min.empty() && max.top() > min.top()) {
            int maxVal = max.top();
            int minVal = min.top();

            max.pop();
            min.pop();

            max.push(minVal);
            min.push(maxVal);

        }
        // 중간 값 출력 !
        cout << max.top() << "\n";
    }


    return 0;
}