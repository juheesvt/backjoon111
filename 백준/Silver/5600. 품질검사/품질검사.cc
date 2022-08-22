#include <iostream>
using namespace std;
#define BROKEN 0
#define NORMAL 1
#define UNKNOWN 2
 
typedef struct {
    int first, second, third;
    bool result;
} checker;
 
int a, b, c, N, temp;
int parts[301];
checker checkers[1001];
 
void findBrokenPart(int idx) {
    int normalCnt = 0;
    if (parts[checkers[idx].first] == NORMAL) normalCnt++;
    if (parts[checkers[idx].second] == NORMAL) normalCnt++;
    if (parts[checkers[idx].third] == NORMAL) normalCnt++;
 
    if (normalCnt == 2) {
        if (parts[checkers[idx].first] == UNKNOWN) parts[checkers[idx].first] = BROKEN;
        if (parts[checkers[idx].second] == UNKNOWN) parts[checkers[idx].second] = BROKEN;
        if (parts[checkers[idx].third] == UNKNOWN) parts[checkers[idx].third] = BROKEN;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    cin >> a >> b >> c >> N;
 
    // 모드 부품을 알 수 없는 상태로 설정
    for (int i = 1; i <= a + b + c; ++i)
        parts[i] = UNKNOWN;
 
    // 검사 결과
    for (int i = 1; i <= N; i++) {
        cin >> checkers[i].first >> checkers[i].second >> checkers[i].third >> temp;
        checkers[i].result = temp == 1 ? true : false;
    }
 
    // 정상으로 판단된 검사를 토대로 해당 부품들을 정상으로 처리
    for (int i = 1; i <= N; i++) {
        if (checkers[i].result) {
            parts[checkers[i].first] = NORMAL;
            parts[checkers[i].second] = NORMAL;
            parts[checkers[i].third] = NORMAL;
        }
    }
 
    // 2개의 정상 부품 사이에서 고장난 부품 한 개 찾기
    for (int i = 1; i <= N; i++) {
        if (!checkers[i].result) {
            findBrokenPart(i);
        }
    }
 
    // 정답 출력
    for (int i = 1; i <= a + b + c; ++i)
        cout << parts[i] << endl;
}