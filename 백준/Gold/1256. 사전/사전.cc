#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 101;

int n, m, k, noWord = 0;
string word;

// dp[x][y] : x개의 a와 y개의 z로 만들 수 있는 문자열 수
int dp[MAX][MAX];

int possibleNumOfWord(int a, int z) {
    // 기저에 도착하면 1 리턴
    if (a == 0 || z == 0) return 1;
    if (dp[a][z] != -1) return dp[a][z];

    // dp[x][y] = dp[x-1][y] + dp[x][y-1]
    dp[a][z] = min(possibleNumOfWord(a - 1, z) + possibleNumOfWord(a, z - 1), 1000000000 + 1);
    return dp[a][z];

//    int &ret = dp[a][z];
////     한번 돌아서 그 값을 안다면 값 리턴
//    if (ret != -1) return ret;
////     dp[x][y] = dp[x-1][y] + dp[x][y-1]
//    ret = min(possibleNumOfWord(a - 1, z) + possibleNumOfWord(a, z - 1), 1000000000 + 1);
//    return ret;
}

// 정답이 될 단어 만들기
// a 개수, z 개수, 이전 순번
void getWord(int a, int z, int skip) {
    if (a == 0) {
        for (int i = 0; i < z; ++i) {
            word += 'z';
        }
        return;
    }
    if (z == 0) {
        for (int i = 0; i < a; ++i) word += 'a';
        return;
    }
    // a가 맨앞에 붙고 나머지 a-1, z 로 만들 수 있는 경우수
    int idx = possibleNumOfWord(a - 1, z);

    // 맨앞에 a를 붙이는 경우
    if (skip < idx) {
        word += 'a';
        getWord(a - 1, z, skip);
    }
    else { // 맨앞에 z를 붙이는 경우
        word += 'z';
        getWord(a, z - 1, skip - idx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    memset(dp, -1, sizeof(dp));

    if (k > possibleNumOfWord(n, m)) noWord = 1;
    else getWord(n, m, k - 1);

    if (noWord) cout << -1;
    else cout << word;

    return 0;
}