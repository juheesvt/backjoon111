//
// Created by 강주희 on 2022/06/18.
//

#include <string>
#include <iostream>
#include <vector>

using namespace std;

string A = "123";

int isGoodArr(string arr) {

    int n = arr.length();
    for(int i=1; i<int(n/2)+1; i++) { // i : 검사할 부분 수열의 길이
        for (int j=i; j<n-i+1; j++) { // j : 검사할 부분 수열의 기준, j를 기준으로 양쪽으로 i만큼 검사
            if (arr.substr(j-i,i) == arr.substr(j,i)) {
                return 0;
            }
        }
    }
    return 1;
}

void recursive(string arr, int n) {
    if (arr.length() == n) {
        cout << arr;
        exit(0);
    }

    for (int i=0; i<3; i++) {
        if (isGoodArr(arr + A[i])) {
            recursive(arr + A[i], n);
        }
    }
    return;
}


int main() {
    int n;
    cin >> n;

    recursive("1", n);
    return 0;
}