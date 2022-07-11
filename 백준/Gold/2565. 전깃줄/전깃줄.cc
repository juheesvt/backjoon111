#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> position(n, pair<int, int>(0, 0));

    for (int i=0; i<n; i++)
        cin >> position[i].first >> position[i].second;

    // a 전봇대 기준 정렬
    sort(position.begin(), position.end());

    /*
        1   8
        2   2
        3   9
        4   1
        6   4
        7   6
        9   7
        10 10
    */

    // b 전봇대에서 LIS 구하기
    vector<int> lis (n, 0);
    for (int i=0; i<n; i++) {
        lis[i] = 1;
        for (int j=0; j<i; j++) {
            if (position[j].second < position[i].second) {
                lis[i] = max(lis[i], lis[j]+1);
            }
        }
    }



    cout << n - *max_element(lis.begin(), lis.end());


   return 0;
}