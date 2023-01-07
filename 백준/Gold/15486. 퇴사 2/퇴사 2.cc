#include <cstdio>
#include <vector>
 
using namespace std;
 
int DP[1500000];
vector<pair<int, int>> v;
int n;

int main() {
    scanf("%d", &n);
    v.push_back(make_pair(0, 0));
    for (int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        v.push_back(make_pair(x, y));
    }
    for (int i = 1; i <= n; i++) {
        DP[i+v[i].first] = max(DP[i+v[i].first], DP[i] + v[i].second);
        DP[i+1] = max(DP[i+1], DP[i]);
    }
    printf("%d\n", DP[n+1]);
}