#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int cntLay(int mid, vector<int> &bluelay) {

    int cnt = 0;
    int sum = 0;

    for (int i=0; i<bluelay.size(); i++) {
        if (sum + bluelay[i] > mid) {
            cnt++;
            sum = 0;
        }
        sum += bluelay[i];

        if (i==3 && sum) {
            cnt++;
        }
    }
    return cnt;
}

int main() {

    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int sum = 0;

    vector<int> bluelay (n , 0);
    for (int i=0; i<n; i++) {
        cin >> bluelay[i];
        sum += bluelay[i];
    }


    int l = *max_element(bluelay.begin(), bluelay.end());
    int r = sum;

    int mid, cnt;
    while (l <= r) {
        mid = (l + r) / 2;
        cnt = cntLay(mid, bluelay);

        if (cnt <= m) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << l;
    return 0;
}