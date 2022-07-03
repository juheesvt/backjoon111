#include <iostream>
#include <string>
#include <stack>

using namespace std;

void printStack(stack<char> &s) {
  while (!s.empty()) {
    cout << s.top();
    s.pop();
  }
}

int main() {

  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);

  // <> 안에 있는 문자인지 알려줌
  int flg = 0;

  string str;

  /* string 헤더에 포함.
     getline(입력 스트림 객체, 문자열을 저장할 string 객체, 종결 문자('\n'))
    cin 과 같은 함수는 공백(" ")이나 개행문자("\n")를 기준으로 입력받기 때문에 사용 x
    개행문자가 들어올 때까지 입력받기 */
  getline(cin, str);

  stack<char> stk;
  for (char s : str) {

    /* < 만나면 그 앞에 있던 스택에 저장된 단어를 top 부터 차례대로 출력하기
      이 후, flag 를 1로 바꿔서 현재 괄호 안이라는 표시 ㄱㄱ
      그리고 '<' 출력 */
    if (s=='<') {
      printStack(stk);
      flg = 1;
      cout << s;
    }
    else if (s=='>') {
      flg = 0;
      cout << s;
    }    
    // 공백 만나면 앞에 있던 스택에 저장된 단어를 top부터 차례대로 출력하기
    else if (s ==' ') {
      printStack(stk);
      cout << s;
    }
    else if (flg) {
      cout << s;
    }
    else {
      stk.push(s);
    }
  }
  printStack(stk);
  
  return 0;
}