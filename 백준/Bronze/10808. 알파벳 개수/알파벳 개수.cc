#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    string str;
    cin >> str;

    int freq[26] = {0, };
    for (char s : str) {
        freq[s-'a']++;
    }

    for (int f : freq) {
        cout << f << " ";
    }
}