#include <iostream>
#include <algorithm>
#include <deque>
#include <cstring>
using namespace std;

const int MAX = 1000;

int cards[MAX];
int dp[MAX][MAX];

int game(int l, int r, int target) {
    if (l > r)      return 0;
    if (dp[l][r])   return dp[l][r];

    if (target) {
        int selectL = cards[l] + game(l+1, r, 0);
        int selectR = cards[r] + game(l, r-1, 0);
        return dp[l][r] = max(selectL, selectR);
    } else {
        int selectL = game(l+1, r, 1);
        int selectR = game(l, r-1, 1);
        return dp[l][r] = min(selectL, selectR);
    }
}
int main() {

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;

        for (int i=0; i<n; i++) {
            cin >> cards[i];
        }

        int l = 0, r = n-1;
        game(l, r, 1);
        cout << dp[l][r] << "\n";
        memset(dp, 0, sizeof(dp));

    }
    return 0;
}