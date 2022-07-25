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

    int s;
    cin >> s ;

    vector<vector<pair<int, int>>> graph (n+1);
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(w, v);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> distance (n+1, INT_MAX);

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
            }
        }
    }

    for (int i=1; i<n+1; i++) {
        if (INT_MAX == distance[i])
            cout << "INF" << "\n";
        else
            cout << distance[i] << "\n";
    }
    return 0;
}

