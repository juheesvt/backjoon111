#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> tri (n, 0);
    for (int i=0; i<n; i++) {
        cin >> tri[i];
    }

    sort(tri.begin(), tri.end(), [] (int a, int b) {
        return a > b;
    });

    int flag = 0;
    for (int i=0; i<n-2; i++) {
        if (tri[i] < tri[i + 1] + tri[i + 2]) {
            cout << tri[i] + tri[i + 1] + tri[i + 2];
            flag = 1;
            break;
        }
    }
    if (!flag)
        cout << -1;

    return 0;
}

