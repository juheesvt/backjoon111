#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int answer = -1;

    // n : 사람 수
    int n;
    cin >> n;

    int src, dst;
    cin >> src >> dst;

    // n2: 입력받을 부모-자식 쌍의 갯수
    int n2;
    cin >> n2;


    // 가족 트리 생성
    vector<vector<int>> familyTree (n+1, vector<int>(0, 0));
    int a, b;
    for (int i=0; i<n2; i++) {
        cin >> a >> b;
        familyTree[a].push_back(b);
        familyTree[b].push_back(a);
    }

    vector<int> visited(n+1, 0);

    queue<vector<int>> q;

    visited[src] = 1;
    q.push({src, 0});
    
    int current, cnt;
    while (!q.empty()) {
        current = q.front()[0];
        cnt = q.front()[1];
        q.pop();

        if (current == dst) {
            answer = cnt;
        }

        for (int i : familyTree[current]) {
            if (!visited[i]) {
                visited[i] = 1;
                q.push({i, cnt+1});
            }
        }
    }

    cout << answer;

    return 0;

}