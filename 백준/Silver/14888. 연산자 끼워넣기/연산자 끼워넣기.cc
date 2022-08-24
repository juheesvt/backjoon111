#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <string>
#include <queue>
#include <map>
#include <climits>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    // + - * /
    vector<int> oper(4, 0);
    vector<char> operArr;

    int n;
    cin >> n;

    vector<int> num(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> oper[i];
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < oper[i]; j++) {
            if (i == 0) {
                operArr.push_back('+');
            } else if (i == 1) {
                operArr.push_back('-');
            } else if (i == 2) {
                operArr.push_back('*');
            } else {
                operArr.push_back('/');
            }
        }
    }
    
    sort(operArr.begin(), operArr.end());
    vector<vector<char>> permutations;
    do {
        permutations.push_back(operArr);
    } while (next_permutation(operArr.begin(), operArr.end()));
    permutations.push_back(operArr);


    int max = INT_MIN;
    int min = INT_MAX;
    for (auto permutation: permutations) {

        int result = num[0];

        for (int i = 0; i < n - 1; i++) {
            if (permutation[i] == '+') {
                result += num[i + 1];
            } else if (permutation[i] == '-') {
                result -= num[i + 1];
            } else if (permutation[i] == '*') {
                result *= num[i + 1];
            } else {
                result /= num[i + 1];
            }
        }

        if (result > max) max = result;
        if (result < min) min = result;
    }

    cout << max << "\n" << min;
    return 0;
}
