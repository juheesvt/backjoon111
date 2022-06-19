//
// Created by 강주희 on 2022/06/18.
//

#include <string>
#include <iostream>
#include <vector>

using namespace std;

// 3x3 부분 행렬 내의 원소들을 뒤집는 함수
void flip(vector<vector<int>> &A, int r, int c) {
    for (int i=r; i<r+3; i++) {
        for (int j=c; j<c+3; j++) {
            A[i][j] = 1 - A[i][j];
        }
    }
}

bool isSame(vector<vector<int>> &A, vector<vector<int>> &B, int n, int m) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (A[i][j] != B[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {

    int n, m;
    int flag = 0;
    cin >> n >> m;

    string tmp;

    vector<vector<int>> A (n, vector<int> (m, 0));
    vector<vector<int>> B (n, vector<int> (m, 0));



    for (int i=0; i<n; i++) {
        cin >> tmp;
        for (int j=0; j<m; j++) {
            A[i][j] = int(tmp[j])-48;
        }
    }
    for (int i=0; i<n; i++) {
        cin >> tmp;
        for (int j=0; j<m; j++) {
            B[i][j] = int(tmp[j])-48;
        }
    }
    
    /*
     * 1 1
     * 1
     * 1
     * 
     * */
    if (isSame(A, B, n, m)) {
        cout << 0;
        return 0;
    }

    int cnt = 0;
    for (int i=0; i<n-2; i++) {
        for (int j=0; j<m-2; j++) {
            if (A[i][j] != B[i][j]) {
                flip(A, i, j);
                cnt++;
            }
            if (isSame(A, B, n, m)) {
                flag = 1;
                break;
            }
        }
        if (isSame(A, B, n, m)) {
            flag = 1;
            break;
        }
    }

    // flag를 사용해서 isSame 중복 호출로 인한 오버헤드 막기
    if (flag)
        cout << cnt;
    else
        cout << -1;

    return 0;

}