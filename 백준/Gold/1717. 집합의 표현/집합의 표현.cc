#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
const int MAX = 1000000;

int root[MAX];

int find(int node) {
    if (root[node] == node)
        return node;
    else
        return root[node] = find(root[node]);
}

void uni(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    root[pb] = pa;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int num, calc;
    cin >> num >> calc;

    for (int i=0; i<=num; i++){
        root[i] = i;
    }

    int cmd, a, b;
    for (int i=0; i<calc; i++) {
        cin >> cmd >> a >> b;
        if (cmd==0) {
            uni(a, b);
        } else {
            if (find(a)==find(b)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        };
    }

    return 0;
}