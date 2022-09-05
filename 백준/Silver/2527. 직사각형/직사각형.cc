#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <string>
#include <queue>
#include <map>
#include <climits>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    for (int i=0; i<4; i++) {
        int x1, y1, p1, q1, x2, y2, p2, q2;
        cin >> x1 >> y1 >> p1 >> q1 >> x2 >> y2 >> p2 >> q2;

        if (p1 < x2 || p2 < x1 || y1 > q2 || q1 < y2) {
            cout << "d\n";
            continue;
        } else if (x1 == p2 || x2 == p1) {
            if (q1 == y2 || q2 == y1) {
                cout << "c\n";
                continue;
            } else {
                cout << "b\n";
                continue;
            }
        } else if (q1 == y2 || q2 == y1) {
            cout << "b\n";
            continue;
        } else {
            cout << "a\n";
            continue;
        }
    }

    return 0;
}
