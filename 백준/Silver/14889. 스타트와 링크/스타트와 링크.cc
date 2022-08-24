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

vector<pair<vector<int>, vector<int>>> combinations;

void combinationFunc(int n, vector<int> com, int r, int idx, int depth) {
    if (r == 0) {
        vector<int> tmp;
        for (int i=1; i<=n; i++) {
            if (find(com.begin(), com.end(), i) == com.end()) {
                tmp.push_back(i);
            }
        }
        combinations.emplace_back(com, tmp);
    } else if (depth == n+1) {
        return;
    } else {
        com[idx] = depth;
        combinationFunc(n, com, r-1, idx+1, depth+1); // 뽑은 경우
        combinationFunc(n, com, r, idx, depth+1);            // 뽑지 않은 경우
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> synergy (n, vector<int> (n, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> synergy[i][j];
        }
    }

    int min = INT_MAX;

    vector<int> com (n/2, 0);
    combinationFunc(n, com, n/2, 0, 1);

    for (const auto& combination : combinations) {
        int start = 0;
        for (auto i : combination.first) {
            for (auto j : combination.first) {
                start += synergy[i-1][j-1];
            }
        }
        int link = 0;
        for (auto i : combination.second) {
            for (auto j : combination.second) {
                link += synergy[i-1][j-1];
            }
        }
        if (min > abs(start-link)) {
            min = abs(start-link);
        }
    }
    cout << min;

    return 0;
}
