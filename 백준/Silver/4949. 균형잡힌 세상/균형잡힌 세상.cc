#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <string>
#include <queue>
#include <map>
#include <climits>
#include <stack>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    string str;
    stack<char> stack;

    while (1){
        getline(cin, str);

        if (str == ".")     break;

        for (auto &cha : str) {
            switch (cha) {
                case '{':
                case '(':
                case '[':
                    stack.push(cha);
                    break;

                case '}':
                    if (!stack.empty() && stack.top() == '{') {
                        stack.pop();
                    } else {
                        stack.push('.');
                    }
                    break;
                case ')':
                    if (!stack.empty() && stack.top() == '(') {
                        stack.pop();
                    } else {
                        stack.push('.');
                    }
                    break;
                case ']':
                    if (!stack.empty() && stack.top() == '[') {
                        stack.pop();
                    } else {
                        stack.push('.');
                    }
                    break;
            }
        }
        if (stack.empty())  cout << "yes" << "\n";
        else                cout << "no" << "\n";

        while (!stack.empty())  stack.pop();
    }


    return 0;
}
