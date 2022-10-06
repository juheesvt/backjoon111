#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>



using namespace std;

#define cost first
#define client second

int c, n;
vector<pair<int, int>> city;

int main() {

    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> c >> n;

    int tmp1, tmp2;
    for (int i=0; i<n; i++) {
        cin >> tmp1 >> tmp2;
        city.emplace_back(tmp1, tmp2);
    }

    vector<int> cache (c+1, 0);
    // 0번째 인덱스에 값 넣어주면 틀림 ~ ㅜㅜ
    for (int i=1; i<c+1; i++)   cache[i] = 9e8;

    // 0~N-1까지 반복문을 돌려주면서 i번 도시까지 홍보할때의 최솟값을 DP 배열에 순차적으로 저장
    for (int i=0; i<n; i++) {
        for (int j=1; j<c+1; j++) {
            // 배수 역할
            for (int k=1; ; k++) {
                int value = 0;
                if (j-city[i].client*k >= 0) {
                    value = cache[j-city[i].client*k];
                }
                if (cache[j] > value + city[i].cost*k) {
                    cache[j] = value + city[i].cost*k;
                }
                else {
                    break;
                }
            }
        }
    }

    cout << cache[c];

    return 0;
}