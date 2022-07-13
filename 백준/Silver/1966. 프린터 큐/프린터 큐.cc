#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

#define index first
#define prior second
using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        int n, targetIdx;
        deque<pair<int, int>> q (n, pair<int, int> (2, 0));

        int p;
        cin >> n >> targetIdx;
        for (int i=0; i<n; i++) {
            cin >> p;
            q.emplace_back(i, p);
        }
        
        int cnt = 1;
        pair<int, int> tmp;

        // 궁금한 index가 큐의 맨 앞에 올 때 까지
        while (1) {

            // front의 우선순위가 max값이 아니라면
            if (q.front().prior != (*max_element(q.begin(), q.end(), [] (pair<int, int> a, pair<int, int> b) {
                return a.prior < b.prior;
            })).prior) {

                // 앞에 있는거 빼서 맨 뒤에 넣어주기
                tmp = q.front();
                q.push_back(tmp);
                q.pop_front();
            }
            else {
                // 아니면 출력해주기
                if (q.front().index == targetIdx) {
                    q.pop_front();
                    break;
                }
                q.pop_front();
                cnt++;
            }

        }
        cout << cnt << "\n";
    }


    return 0;
}