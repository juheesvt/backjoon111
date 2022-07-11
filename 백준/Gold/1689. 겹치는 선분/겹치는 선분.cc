#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first < b.first;
}

int main() {

    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int a, b;
    vector<pair<int, int>> line;
    for (int i=0; i<n; i++) {
        cin >> a >> b;
        line.emplace_back(a, 1);
        line.emplace_back(b, -1);
    }

    sort(line.begin(), line.end(), cmp);

    int answer = 0;
    int cnt = 0;
    for (int i=0; i<line.size(); i++) {
        cnt += line[i].second;
        answer = max(answer, cnt);
    }
    cout << answer;


   return 0;
}