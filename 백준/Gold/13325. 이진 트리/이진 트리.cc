#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int tree[1 << 21];
int treeSize;
int ret = 0;


int solve(int node) {
    // 리프노드일때
    if (node * 2 >= treeSize) {
        ret += tree[node];
        return tree[node];
    }else {
        int left = solve(node * 2);
        int right = solve(node * 2 + 1);
        ret += abs(left - right) + tree[node];
        return tree[node] + max(left, right);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int t;
    cin >> t;
    treeSize = 1 << (t + 1);

    // index tree
    for (int i = 2; i < treeSize; i++) {
        cin >> tree[i];
    }
    // root는 1
    // 1 23 4567 (0은 비워둠)
    solve(1);
    cout << ret << '\n';

    return 0;
}