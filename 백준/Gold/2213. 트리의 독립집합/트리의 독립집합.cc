#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 100001;

int n;
int cost[MAX];
int cache[MAX][2];
int visited[MAX];
vector<int> tree[MAX];
vector<int> path;

// 서로 인접하지 않는 정점들의 가중치의 최댓값을 찾는 문제

void dfs(int now) {
    // now가 독립집합에 포함될때
    cache[now][0] = 0;
    // now가 독립집합에 포함되지않을 때
    cache[now][1] = cost[now];

    visited[now] = 1;

    for (int i=0; i<tree[now].size(); i++) {
        int next = tree[now][i];
        if (visited[next]) continue;

        dfs(next);
        cache[now][0] += max(cache[next][0], cache[next][1]);
        cache[now][1] += cache[next][0];
    }
}

void tracing(int now, int prev) {

    // 자신이 선택되었을 때의 최댓값이 선택되지 않았을때의 최댓값보다 크다면 해당 노드는 최댓값을 이루는 구성요소가 된다.
    if(cache[now][1] > cache[now][0] && !visited[prev]){
        path.push_back(now);
        visited[now] = true;
    }

    for(int i = 0; i < tree[now].size(); i++){
        int next = tree[now][i];
        if(next == prev) continue;
        tracing(next, now);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> cost[i];
    }

    int a, b;
    for (int i=1; i<n; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1);
    memset(visited, 0, sizeof(visited));
    tracing(1, 0);

    sort(path.begin(), path.end());

    cout << max(cache[1][0], cache[1][1]) << "\n";
    for (auto &w : path)
        cout << w << " ";



    return 0;
}