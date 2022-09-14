#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <set>

using namespace std;

vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};

int gcb(int a, int b) {
    if (b == 0) return a;
    else {
        return gcb(b, a % b);
    }
}

int main() {

    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int t;
    cin >> t;


    vector<int> v;
    v.push_back(0);

    // 1000 까지의 입력에 대해 모두 구해놓기
    int cnt = 0;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j < i; j++) {
            if (gcb(i, j) == 1) cnt++;
        }
        v.push_back(cnt);
    }

    while (t--) {
        int n;
        cin >> n;
        cout << v[n] * 2 + 3 << "\n";
    }


    return 0;
}
