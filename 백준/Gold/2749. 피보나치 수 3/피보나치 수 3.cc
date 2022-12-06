#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

/*
 * n 번째 피보나치 수를 10의 6승으로 나눈 나머지는  n % p(주기) 번째 피보나치 수를 10의 6승으로 나눈 나머지와 같다
 */

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    long long a[1500050]; // 1000000으로 나눈 피보나치 수열의 반복되는 주기는 1500000, m = 10^k 일때, p는 15*10^(k-1)
    int m = 1000000;

    a[0] = 0;
    a[1] = 1;
    for (int i=0; i<1500000; i++) {
        a[i+2] = (a[i+1] + a[i]) % m;
    }
    cout << a[n%1500000];

    return 0;
}