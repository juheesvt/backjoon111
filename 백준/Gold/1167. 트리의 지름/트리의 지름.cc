#include <iostream>
#include <vector>
#include <queue>
#include <climits>

/*
 * [트리의 지름 알고리즘]

    1. 임의의 정점 x에서 가장 멀리 떨어진 정점 u를 찾는다

    2. 1에서 찾은 정점 u에서 가장 멀리 떨어진 정점 v를 찾는다

    3. u - v가 트리의 지름이 된다.
 */

using namespace std;

int n;
int visited[100001];
vector<pair<int, int>> tree[100001];

int startNode = 0;
int maxVal = 0;

void dfs(int node, int distance) {

    visited[node] = 1;
    if (distance > maxVal) {
        startNode = node;
        maxVal = distance;
    }
    for (auto t : tree[node]) {
        if (visited[t.first])
            continue;
        dfs(t.first, distance + t.second);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    // 트리 입력
    cin >> n;

    for (int i=1; i<n+1; i++) {
        int node1;
        cin >> node1;

        while (1) {
            int node2, w;
            cin >> node2;
            if (node2 == -1)
                break;
            cin >> w;
            tree[node1].emplace_back(node2, w);
        }
    }

    dfs(1, 0);
    maxVal = 0;
    fill(visited, visited + 100001, 0);

    dfs(startNode, 0);
    cout << maxVal;

    return 0;
}