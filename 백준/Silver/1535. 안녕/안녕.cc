//
// Created by 강주희 on 2022/06/18.
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int W = 0;
const int V = 1;

int main() {

    int n;

    const int HP = 100;


    cin >> n;

    vector<vector<int>> people (n, vector<int>(2, 0));
    for(int i=0; i<n; i++) {
        cin >> people[i][W];
    }
    for (int i=0; i<n; i++) {
        cin >> people[i][V];
    }

    int maxVal = 0;
    vector<vector<int>> cache (n+1, vector<int>(HP, 0));
    for (int i=1; i<=n; i++) {
        for (int j=0; j<HP; j++) {
            if (people[i-1][W] <= j) {
                cache[i][j] = max(people[i-1][V] + cache[i-1][j-people[i-1][W]], cache[i-1][j]);
            }
            else {
                cache[i][j] = cache[i-1][j];
            }
            maxVal = max(cache[i][j], maxVal);
        }
    }

    cout << maxVal;

    return 0;
}