#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100001;

int n, cnt;
int want[MAX];
int visited[MAX];
int done[MAX];


void dfs(int node) {
    visited[node] = 1;

    int next = want[node];
    if (!visited[next]) {
        dfs(next);
    } else if (!done[next]){ // 이미 방문했지만 방문이 끝난 노드가 아니라면 사이클
        // 원하는 팀원 타고타고 들어가서 팀원 세기
        for (int i=next; i != node; i=want[i]) {
            cnt++;
        }
        cnt++; // 자기 자신 추가
    }

    // 더이상 노드를 방문할 일이 없음
    done[node] = 1;



}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    /*
        사이클을 이루는 학생들끼리 같은 팀 -> 사이클을 이루지 않는 사람의 수를 구하는 문제
     */


    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        memset(visited, 0, sizeof(visited));
        memset(done, 0, sizeof(done));

        cin >> n;

        for (int j=1; j<=n; j++) {
            cin >> want[j];
        }

        cnt = 0;
        for (int j=1; j<=n; j++) {
            if (!visited[j]) {
                dfs(j);
            }
        }

        cout << n - cnt << "\n";
    }

    return 0;
}