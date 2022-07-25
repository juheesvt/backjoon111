#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph (n+1);
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(w, v);
    }

    int s, e;
    cin >> s >> e;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> distance (n+1, INT_MAX);
    vector<int> pre (n+1, 0);

    distance[s] = 0;
    pq.push({distance[s], s});

    while (!pq.empty()) {

        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (weight != distance[node])
            continue;

        for (auto &next : graph[node]) {
            int nextWeight = next.first;
            int nextNode = next.second;

            if (distance[nextNode] > distance[node] + nextWeight) {
                distance[nextNode] = distance[node] + nextWeight;
                pq.push({distance[nextNode], nextNode});
                pre[nextNode] = node;
            }
        }
    }

    cout << distance[e] << "\n";

    vector<int> path;

    int current = e;
    while (current != s) {
        path.push_back(current);
        current = pre[current];
    }
    path.push_back(current);
    reverse(path.begin(), path.end());

    cout << path.size() << '\n';
    for (auto x : path) {
        cout << x << " ";
    }
    return 0;
}

