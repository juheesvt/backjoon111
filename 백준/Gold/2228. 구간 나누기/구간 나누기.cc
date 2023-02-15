#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 100;

int n, m;
int line[MAX];
int sum[MAX][MAX];
int cache[MAX][MAX];

int dp(int currentN, int currentM) {
    if (currentM == m) return 0;
    if (currentN >= n) return -987654321;

    if (cache[currentN][currentM] != -1) return cache[currentN][currentM];

    // n을 어느구간에도 포함시키지않은 경우 (n만 1 증가)
    cache[currentN][currentM] = dp(currentN + 1, currentM);
    // n번째 원소를 첫번째 원소로 해서 만들 수 있는 모든 구간 구하기
    for (int i=currentN; i<n; i++) {
        cache[currentN][currentM] = max(cache[currentN][currentM], sum[currentN][i] + dp(i+2, currentM+1));
    }
    return cache[currentN][currentM];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    memset(cache, -1, sizeof(cache));

    for (int i=0; i<n; i++) {
        cin >> line[i];
    }
    for (int i=0; i<n; i++) {
        int subSum = 0;
        for (int j=i; j<n; j++) {
            subSum += line[j];
            sum[i][j] = subSum;
        }
    }

    cout <<  dp(0, 0);

    return 0;
}