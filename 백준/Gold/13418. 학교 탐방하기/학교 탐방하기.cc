#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <string>
#include <queue>


using namespace std;


int N, M, uf[1001];
struct P {
    int u, v, w;
};
vector<P> v;

int find(int a) {
    if (uf[a] == a)
        return a;
    return uf[a] = find(uf[a]);
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
        return 0;
    uf[a] = b;

    return 1;
}

int kruskal() {
    for (int i = 0; i <= N; i++)
        uf[i] = i;

    int cnt = 0, ret = 0;
    for (int i = 0; i < v.size(); i++) {
        if (merge(v[i].u, v[i].v)) {
            if (v[i].w == 0)
                ret++;
            if (++cnt == N)
                break;
        }
    }
    return ret * ret;
}

int main() {

    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> N >> M;
    M++;
    while (M--) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, b, c});
    }

    // 피로도가 최소가 되게 하려면 내리막을 우선 선택해야하므로, cost 내림차순 정렬 !
    sort(v.begin(), v.end(), [](P &u, P &v) {
        return u.w < v.w;
    });
    int ans = kruskal();


    sort(v.begin(), v.end(), [](P &u, P &v) -> bool {
        return u.w > v.w;
    });
    ans -= kruskal();
    cout << ans;
}
