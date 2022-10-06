#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;
using namespace std;

const int MAX_N = 50;
int parent[MAX_N];
vector<pair<int, int>> edge;

int uf(int node) {
    if (node == parent[node]) {
        return node;
    }

    return parent[node] = uf(parent[node]);
}

void unite(int a, int b) {
    parent[uf(b)] = uf(a);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);


    int ans[MAX_N];
    memset(ans, 0, sizeof(ans));
    int roadCount = 0;

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < N; ++i) {
        string line;
        cin >> line;

        // 주어진 입력이 대칭 행렬이라서 i < j 인 경우는 무시. j = i+1 부터 시작 !
        // 그리고 그리디하게 입력을 받을 수 있음
        for (int j = i + 1; j < N; ++j) {
            if (line[j] == 'Y') {

                // 아직 연결이 안되어있으면
                if (uf(i) != uf(j)) {
                    // 연결 !
                    unite(i, j);
                    // 도로의 갯수 추가
                    roadCount++;
                    // 각 도시(i, j)를 끝 점으로 갖는 도로의 갯수 추가
                    ans[i]++;
                    ans[j]++;
                } else {
                    // 이미 연결된 도로는 edge 벡터에 저장
                    edge.emplace_back(i, j);
                }
            }
        }
    }

    // 모든 도시를 연결할 수 없다면 -1 출력
    if (roadCount != N - 1) {
        cout << -1 << endl;
        return 0;
    }


    for (int i = N - 1; i < M; ++i) {
        if (edge.empty()) {
            cout << -1 << endl;
            return 0;
        }

        // 도로의 양 끝에다가 ++ !
        ans[edge.front().first]++;
        ans[edge.front().second]++;
        edge.erase(edge.begin());
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }

    return 0;
}