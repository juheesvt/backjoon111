#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <string>
#include <queue>


using namespace std;




int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int answer = 2147483647;


    int n;
    cin >> n;

    vector<pair<int, int>> v (n , pair<int, int>(2, 0));
    for (int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    for (int i=1; i<(1<<n); i++) {
        int a = 1, b = 0;
        for (int j=0; j<n; j++) { // n-1칸 left shift
            if (i & (1<<j)) {
                a *= v[j].first;
                b += v[j].second;
            }
        }
        answer = min(answer, abs(a-b));
    }
    cout << answer;

    return 0;
}
