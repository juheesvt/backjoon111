#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n, tmp;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> card;
    for (int i=0; i<n; i++) {
        cin >> tmp;
        card.push(tmp);
    }

    int a, b;
    int cnt = 0;
    while(card.size() > 1) {

        a = card.top();
        card.pop();

        b = card.top();
        card.pop();

        cnt += a + b;
        card.push(a+b);

    }
    cout <<cnt ;

    return 0;

}
