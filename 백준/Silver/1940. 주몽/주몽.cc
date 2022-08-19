#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <string>
#include <queue>
#include <map>


using namespace std;




int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> numbers (n, 0);
    for (int i=0; i<n; i++) {
        cin >> numbers[i];
    }

    map<int, int> dict;
    int answer = 0;
    for (int i=0; i<n; i++) {
        if (dict.find(m-numbers[i]) != dict.end()) {
            answer++;
        }
        else {
            dict.emplace(numbers[i], m-numbers[i]);
        }
    }
    cout << answer;

    return 0;
}
