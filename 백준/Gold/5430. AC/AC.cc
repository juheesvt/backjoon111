#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <string>
#include <queue>


using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int testCase;
    cin >> testCase;

    while (testCase--) {

        int size;
        deque<string> numbers;

        string func;
        string origin;

        cin >> func >> size >> origin;

        // https://codechacha.com/ko/cpp-substring/ find()와 substr() 로 구분

        origin = origin.substr(1, origin.size()-2);
        string separator = ",";

        int position;
        int curPosition = 0;
        while ((position = origin.find(separator, curPosition)) != string::npos) {
            int len = position - curPosition;
            numbers.push_back(origin.substr(curPosition, len));
            curPosition = position + 1;
        }
        numbers.push_back(origin.substr(curPosition));
        // 함수 처리

//        for (auto a: numbers) cout << a << " ";

        int error = 0;
        int flag = 0;
        for (auto &f : func) {
            if (f == 'R') {  // 뒤집기
                flag = 1 - flag;
            } else {         // 버리기
                if (numbers.size() == 0 || (numbers.size() == 1 && numbers[0] == "\0"))   {
                    error = 1;
                    break;
                }
                else {
                    if (flag)
                        numbers.pop_back();
                    else
                        numbers.pop_front();
                }
            }
        }

        // 오류ㅇ아니면 리스트에 남아잇는거 출력
        if (error)      {
            cout << "error" << "";
        }
        else {
            cout << "[";

            if (flag) {
                for (int i=numbers.size()-1; i>=0; i--) {
                    cout << numbers[i];
                    if (i != 0)
                        cout << ",";
                }
                cout << "]";
            } else {
                for (int i = 0; i < numbers.size(); i++) {
                    cout << numbers[i];
                    if (i != numbers.size() - 1)
                        cout << ",";
                }
                cout << "]";
            }
        }
        cout << "\n";
    }

    return 0;
}