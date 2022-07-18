#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


const int D = 0;
const int W = 1;

struct cmp {
    bool operator() (vector<int> x, vector<int> y) {
        return x[W] > y[W];
    }
};

int main() {

    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> homework (n, vector<int> (2, 0));

    for (int i=0; i<n; i++) {
        cin >> homework[i][D] >> homework[i][W];
    }

    sort(homework.begin(), homework.end(), [] (vector<int> x, vector<int> y) {
        if (x[D] == y[D])   return x[W] > y[W];
        return x[D] < y[D];
    });

    int day = 1;
    int score = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

    for (int i=0; i<n; i++) {
        if (homework[i][D] >= day) {
            pq.push(homework[i]);
            score += homework[i][W];
            day++;
        }
        else {
            if (homework[i][W] > pq.top()[W]) {
                    score -= pq.top()[W];
                    score += homework[i][W];
                    pq.pop();
                    pq.push(homework[i]);
            }
        }
    }
    
    cout << score;
    return 0;
}