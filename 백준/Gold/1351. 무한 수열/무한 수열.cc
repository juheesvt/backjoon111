#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

const int MAX = 52;

long long P, Q;
map<long long, long long> cache;

long long solve(long long n) {
    if (n == 0) return 1;

    if (cache[n] != 0) return cache[n];
    return cache[n] = solve(n/P) + solve(n/Q);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n;
    cin >> n >> P >> Q;
    cout << solve(n);


    return 0;
}