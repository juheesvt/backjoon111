#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

/*
 * N -> X -> N 으로 오는 최단 거리 중 가장 긴 거리를 찾는 문제
 *
 * N -> X : 최단 거리를 N의 개수 만큼 반복문을 돌려서 다익스트라 알고리즘 수행
 * X -> N : 다익스트라 한번 수행
 *
 * 정점들의 정보를 입력 받을 때, 역방향 간선을 따로 입력 받기
 * > 역방향으로 입력을 받으면 각 정점들에서 X로 가는 최단거리를 X->N 최단 거리로 바꿀 수 있음
 */

int n, m, x;
vector<pair<int, int>> graph[2][1001];
vector<int> dist[2];

const int INF = 1e9+7;

const int GO = 1;
const int BACK = 0;

void dijstra(int k){

    // 시작 정점까지의 거리 0으로 초기화
    dist[k][x] = 0;

    // { 가중치, 정점 }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.push({0, x});

    while (!q.empty()) {

        // 우선순위큐에서 거리 가중치가 제일 작은거 가져오기
        int minCost = q.top().first;
        int now = q.top().second;
        q.pop();

        // 거리 배열에 저장된거 보다 크면 PASS
        if(minCost > dist[k][now])
            continue;


        for (int i = 0; i < graph[k][now].size(); i++){
            int next = graph[k][now][i].second;
            int nextCost = minCost + graph[k][now][i].first;

            // 거쳐 가는게 저장되어 있는것보다 작으면, 최단 거리 갱신하고, 우선순위 큐에 집어넣기
            if(nextCost < dist[k][next]){
                dist[k][next] = nextCost;
                q.push({nextCost, next});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int u, v, t;
    cin >> n >> m >> x;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> t;
        graph[0][u].emplace_back(t, v);
        graph[1][v].emplace_back(t, u);     // 역방향
    }

    // 모든 정점까지의 거리 무한대로 초기화
    dist[0].resize(n+1, INT_MAX);
    dist[1].resize(n+1, INT_MAX);

    // 정점들에서 X로 가는 최단거리
    dijstra(GO);

    // X에서 정점들로 가는 최단거리
    dijstra(BACK);

    int maxVal = 0;
    for(int i = 1; i < n+1; i++){
        // 갔다 오는거 중에서 제일 큰 값 갱신
        maxVal = max(maxVal, dist[GO][i] + dist[BACK][i]);
    }

    cout << maxVal;

    return 0;
}