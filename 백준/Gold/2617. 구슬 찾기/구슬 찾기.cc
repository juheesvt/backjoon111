#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 100;

int n, m;
int answer = 0;
int visited[MAX];

int bfs(vector<vector<int>> &graph, int targetNode) {


    memset(visited, 0, sizeof(visited));

    queue<int> q;
    visited[targetNode] = 1;
    q.push(targetNode);

    int cnt = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto nextNode : graph[cur]) {
            if (visited[nextNode]) continue;
            q.push(nextNode);
            visited[nextNode] = 1;
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    vector<vector<int>> in(n + 1);  // (u, v) : u > v
    vector<vector<int>> out(n + 1); // (u, v) : u < v

    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        in[u].push_back(v);
        out[v].push_back(u);
    }

    int middle = (n-1)/2;
    for (int node=1; node<=n; node++) {
        int big = bfs(out, node);    // node 구슬보다 무거운 구슬의 갯수
        int small = bfs(in, node);   // node 구슬보다 가벼운 구슬의 갯수

        if (big > middle || small > middle) answer += 1;
    }

    cout << answer;

    return 0;
}