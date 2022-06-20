//
// 가장 긴 증가하는 부분 수열
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    string str;
    char stack[2001] = {-1, };

    int p = 0;
    int cnt = 0;

    while(1) {
        p++;
        cin >> str;

        if (str[0] == '-')
            break;

        int idx = -1;
        int cnt = 0;
        for (char s : str) {
            stack[++idx] = s;

            if (idx >= 1) {
                if (stack[idx] == '}') {
                    if (stack[idx - 1] == '{') {
                        idx -= 2;
                    }
                }
            }
        }

        int open = 0;
        int close = 0;
        int answer = 0;

        for (int i=0; i<=idx; i++) {
            if (stack[i] == '{') {
                open++;
                if (close < open) {
                    close++;
                    open--;
                    answer++;
                }

            }
            else {
                close++;
                if (open < close) {
                    open++;
                    close--;
                    answer++;
                }
            }

        }
        printf("%d. %d\n", p, answer);

    }




}