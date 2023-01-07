#include <iostream>
#include <string>
#include <string.h>
#define MAX 5001
#define divider 1000000
 
using namespace std;
 
string code;
int cache[MAX];
int answer;
 
bool isZero(char c) {
    if (c == '0') {
        return true;
    }
    return false;
}
 
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
    점화식 : D[i] = D[i-1] + D[i-2]
    ------------------------
    D[i] : i번째 <까지> 해석될 수 있는 암호의 수
    */
    cache[0] = cache[1] = 1;
    for (int i = 2; i <= s.length(); i++) {
        cache[i] = isZero(s[i-1]) ? 0 : cache[i - 1];
        cache[i] += canChangeAlpha(s.substr(i - 2, 2)) ? cache[i - 2] : 0;
        cache[i] %= divider;
    }
 
    return cache[s.length()];
}
 
int main() {
 
    //초기화
    code = "";
    memset(cache, -1, sizeof(cache));
    answer = 0;
 
    //입력
    cin >> code;
 
    //해법
    answer = countDecode(code);
 
    //출력
    cout << answer << "\n";
 
    //종료
    return 0;
}
