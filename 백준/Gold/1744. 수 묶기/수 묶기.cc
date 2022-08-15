#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <string>

using namespace std;

vector<int> dy = {-1, 1, 0, 0};
vector<int> dx = {0, 0, 1, -1};

int main() {

    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int sum = 0;
    int zero = 0;
    vector<int> positive;
    vector<int> negative;

    for (int i=0; i<n; i++) {
        int num;
        cin >> num;

        if (num > 1)            positive.push_back(num);
        else if (num == 1)      sum++;
        else if (num == 0)      zero++;
        else                    negative.push_back(num);
    }

    sort(positive.begin(), positive.end(), greater<>());
    sort(negative.begin(), negative.end(), less<>());


    int positiveSize = positive.size()-(positive.size()%2);
    for (int i=0; i<positiveSize; i +=2) {
        sum += positive[i] * positive[i+1];
    }
    if (positive.size() % 2 == 1) {
        sum += positive.back();
    }

    int negativeSize = negative.size()-(negative.size()%2);
    for (int i=0; i<negativeSize; i +=2){
        sum += negative[i] * negative[i+1];
    }
    if (negative.size() % 2 == 1){
        if (zero == 0){              // 0이랑 -상쇄
            sum += negative.back();
        }
    }


    cout << sum;
    return 0;
}