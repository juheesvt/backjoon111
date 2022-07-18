#include <algorithm>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        priority_queue<int, vector<int>, less<int>> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        map<int, int> sync;

        while (n--) {
            char order;
            int num, prior;

            cin >> order;
            if (order == 'I') {
                cin >> num;
                maxHeap.push(num);
                minHeap.push(num);

                if (sync[num] == 0) {
                    sync[num] = 1;
                }
                else {
                    sync[num]++;
                }
            }
            else {
                cin >> prior;
                if (prior == 1) {
                    while (!maxHeap.empty() && sync[maxHeap.top()] == 0) {            // 최댓값 삭제
                        maxHeap.pop();
                    }
                    if (!maxHeap.empty()) {
                        sync[maxHeap.top()]--;
                        maxHeap.pop();
                    }
                }
                else {
                    while (!minHeap.empty() && sync[minHeap.top()] == 0) {            // 최솟값 삭제
                        minHeap.pop();
                    }
                    if (!minHeap.empty()) {
                        sync[minHeap.top()]--;
                        minHeap.pop();
                    }
                }
            }
        }

        while (!maxHeap.empty() && sync[maxHeap.top()] == 0) {            // 최댓값 삭제
            maxHeap.pop();
        }
        while (!minHeap.empty() && sync[minHeap.top()] == 0) {            // 최댓값 삭제
            minHeap.pop();
        }
        if (maxHeap.empty() || minHeap.empty())      cout << "EMPTY" << "\n";
        else                cout << maxHeap.top() << " " << minHeap.top() << "\n";
    }
    return 0;
}