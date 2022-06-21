#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//int recursive(string a, string b, int aSize, int bSize, int ai, int bi, int depth) {
//
//    if (aSize <= ai || bSize <= bi) {
//        return depth;
//    }
//
//    if (a[ai] == b[bi]) {
//        return recursive(a, b, aSize, bSize, ++ai, ++bi,++depth);
//    }
//    else{
//        return max(recursive(a, b, aSize, bSize, ai, ++bi, depth), recursive(a, b, aSize, bSize, ++ai, bi, depth));
//    }
//
//}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    int aSize = a.length()+1;
    int bSize = b.length()+1;

//    cout << recursive(a, b, aSize, bSize, 0 , 0, 0);

    vector<vector<int>> cache (aSize, vector<int>(bSize, 0));
    for (int i=0; i<aSize; i++) {
        for (int j=0; j<bSize; j++) {
            if (i==0 || j==0)
                cache[i][j] = 0;
            else if (a[i-1] == b[j-1])
                cache[i][j] = cache[i-1][j-1] + 1;
            else
                cache[i][j] = max(cache[i-1][j], cache[i][j-1]);
        }
    }
    int answer = cache[0][0];
    int tmp;
    for (int i=0; i<aSize; i++) {
        tmp = *max_element(cache[i].begin(), cache[i].end());
        if (answer < tmp)
            answer = tmp;
    }
    cout << answer;
}