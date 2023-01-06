#include <cstdio>
#include <vector>
 
using namespace std;
 
int d[1600000];
vector<pair<int, int>> v;
int n;
int ans = 0;
 
int main() {
    scanf("%d", &n);
    v.push_back(make_pair(0, 0));
    for (int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        v.push_back(make_pair(x, y));
    }
    for (int i = 1; i <= n; i++) {
        d[i+v[i].first] = max(d[i+v[i].first], d[i] + v[i].second);
        d[i+1] = max(d[i+1], d[i]);
    }
    printf("%d\n", d[n+1]);
}