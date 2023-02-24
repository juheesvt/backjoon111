#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<char> v;
string s, bomb;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> s >> bomb;

    int sLen = s.size();
    int bombLen = bomb.size();

    for (int i=0; i<sLen; i++) {
        v.push_back(s[i]);

        if (v.size() >= bombLen) {
            int flg = 1;
            for (int j=0; j<bombLen; j++) {
                if (v[v.size()-bombLen+j] != bomb[j]) {
                    flg = 0;
                    break;
                }
            }

            if (flg) {
                for (int j=0; j<bombLen; j++) {
                    v.pop_back();
                }
            }
        }
    }
    
    if (v.empty()) cout << "FRULA";
    else {
        for (char &a : v)
            cout << a;
    }

    return 0;
}