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

    string str, keyword;
    cin >> str >> keyword;

    string str2;

    // 97~122: 소문자 65~90: 대문자
    for (auto & s: str) {
        int ss = int(s);
        if (!((65<=ss && ss<=90) ||  (97<=ss && ss<=122)))
            continue;
        str2 += s;
    }

    if (str2.find(keyword) != string::npos)
        cout << 1;
    else
        cout << 0;
    return 0;
}