#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int cntLan(int lanLength, vector<int> &lan) {

    int cnt = 0;
    for (int l : lan) {
        cnt +=  int(l/lanLength);
    }
    return cnt;
}

int main() {

    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    vector<int> lan (n , 0);
    for (int i=0; i<n; i++)     cin >> lan[i];

    long long sta = 1;
    long long end = *max_element(lan.begin(), lan.end());

    long long mid, length;
    while (sta <= end) {
        mid = (sta + end) / 2;

        length = cntLan(mid, lan);

        if (length < m) {
            end = mid - 1;
        }
        else {
            sta = mid + 1;
        }
    }

    cout << end;
    return 0;
}