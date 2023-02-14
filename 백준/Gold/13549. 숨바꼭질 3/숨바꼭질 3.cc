#include <iostream>
#include <cstring>
#include <deque>
#include <vector>

using namespace std;

const int MAX = 999999;

int n, k;
int dist[100001];

struct Node {
    int current, currentDist;
};

int bfs(int n, int k) {
    memset(dist, MAX, sizeof(dist));
    deque<Node> q;
    q.push_back({n, 0});

    while (!q.empty()) {
        Node node = q.front();
        q.pop_front();

        if (node.current == k) {
            return dist[k];
        }

        // https://www.acmicpc.net/board/view/38887#comment-69010 순서 참고
        /*
           원래 이 문제는 단순한 BFS를 요구하는 문제가 아닙니다. 왜냐하면, BFS를 하기 위해서는 모든 간선의 가중치가 동일해야 한다는 전제 조건이 필요하기 때문입니다. 이 문제는 가중치가 0인 간선이 있기 때문에 일반적으로는 단순한 BFS를 쓸 수 없으나, 문제의 특성 때문에 방문 순서에 따라서 단순 BFS로도 우연히도 항상 정답을 찾을 수 있을 뿐입니다. 왜 하필 이 순서로 하면 항상 정답이 나오는가를 증명하는 건 매우 복잡한 일입니다.

            이 문제를 보다 일반화된 경우 (가중치가 0인 간선이 있는 경우)에 대해 해결하려면, 즉, 이 문제의 의도대로 풀려면 다음과 같은 방법들을 사용할 수 있습니다.

            다익스트라 알고리즘
            0-1 BFS: 가중치가 0인 간선에 연결된 정점은 큐의 맨 뒤가 아닌 맨 앞에 넣는 방법
            2를 별도의 간선으로 생각하지 않고, +1이나 -1에 의한 좌표를 큐에 넣을 때 그 좌표의 2의 거듭제곱 배인 좌표들을 전부 큐에 넣는 방법
         */

        // 점프하는게 이득일 댸
        if (node.current * 2 <= 100000) {
            if (dist[node.current * 2] > node.currentDist) {
                dist[node.current * 2] = node.currentDist;
                q.push_front({node.current * 2, node.currentDist});
            }
        }

        // 뒤로 한칸 가는게 이득일 때
        if (node.current > 0) {
            if (dist[node.current - 1] > node.currentDist + 1) {
                dist[node.current - 1] = node.currentDist + 1;
                q.push_back({node.current - 1, node.currentDist + 1});
            }
        }

        // 앞으로 한칸 가는게 이득일 때
        if (node.current < 100000) {
            if (dist[node.current + 1] > node.currentDist + 1) {
                dist[node.current + 1] = node.currentDist + 1;
                q.push_back({node.current + 1, node.currentDist + 1});
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    if (n == k || n * 2 == k) cout << 0;
    else if (k < n) cout << n - k;
    else cout << bfs(n, k);

    return 0;
}