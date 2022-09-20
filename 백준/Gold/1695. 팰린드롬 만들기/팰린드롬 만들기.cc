#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <numeric>


using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> palindrome(n, 0);
    vector<int> reversePalindrome(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> palindrome[i];
        reversePalindrome[n - i - 1] = palindrome[i];
    }


    int maxVal = 0;
    vector<vector<int>> cache(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (i == 0 || j == 0) {
                cache[i][j] = 0;
            } else if (palindrome[i - 1] == reversePalindrome[j - 1]) {
                cache[i][j] = cache[i - 1][j - 1] + 1;
            } else {
                cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
            }
            if (maxVal < cache[i][j]) {
                maxVal = cache[i][j];
            }
        }
    }
    cout << n - maxVal;
    return 0;
}
