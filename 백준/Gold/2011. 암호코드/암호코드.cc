#include <iostream>
#include <string>
#include <string.h>

using namespace std;

const int MAX = 5001;
const int divider = 1000000;

string code;
int DP[MAX];
 
bool canChangeAlpha(string s) {
    int number = stoi(s);
 
    if (number >= 10 && number <= 26) {
        return true;
    }
    return false;
}
 
int countDecode(string s) {
 
    if (s[0] == '0') {
        return 0;
    }
 
    /*
     * 점화식 : DP[i] = DP[i-1] + DP[i-2]
     * DP[i] : i번째 "까지" 해석될 수 있는 암호의 수
     */
    DP[0] = DP[1] = 1;
    for (int i = 2; i <= s.length(); i++) {
        DP[i] = s[i-1] == '0' ? 0 : DP[i - 1];
        
        // 알파벳 두개
        DP[i] += canChangeAlpha(s.substr(i - 2, 2)) ? DP[i - 2] : 0;
        DP[i] %= divider;
    }
 
    return DP[s.length()];
}
 
int main() {
 
    code = "";
    memset(DP, -1, sizeof(DP));
   
    cin >> code;
 	cout << countDecode(code);
 
    return 0;
}
