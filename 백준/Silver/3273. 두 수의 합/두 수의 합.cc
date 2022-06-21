#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> numbers (n, 0);

    for (int i=0; i<n; i++)
        cin >> numbers[i];

    int x;
    cin >> x;

    vector<int> freq (x+1, 0);
    for (int i=0; i<n; i++) {
        if (numbers[i] < x)
            freq[numbers[i]] = 1;
    }

    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (x-numbers[i] >=0) {
            if (freq[x - numbers[i]]) {
                cnt++;
            }
        }
    }
    cout << cnt/2;
    return 0;
}