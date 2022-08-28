#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <string>
#include <queue>
#include <map>
#include <climits>
#include <stack>


using namespace std;

int n;
string str;
int maxVal = INT_MIN;


int calculate(int a, int b, char o) {
    if (o == '+') {
        return a + b;
    } else if (o == '-') {
        return a - b;
    } else {
        return a * b;
    }
}

void dfs(int idx, int current) {
    if (idx > n - 1) {
        maxVal = max(maxVal, current);
        return;
    }

    char o = (idx == 0 ? '+' : str[idx - 1]);

    // 괄호를 묶었을 때
    if (idx + 2 < n) {
        int tmp = calculate(str[idx] - '0', str[idx + 2] - '0', str[idx + 1]);
        dfs(idx + 4, calculate(current, tmp, o));
    }
    dfs(idx + 2, calculate(current, str[idx] - '0', o));
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> n >> str;
    dfs(0, 0);
    cout << maxVal;

    return 0;
}
