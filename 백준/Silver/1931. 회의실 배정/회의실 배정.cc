#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {

  int n;
  vector<vector<int>> list;

  cin >> n;

  for (int i=0; i<n; i++) {
    int a, b;
    cin >> a >> b;
    list.push_back({b,a});
  }

  // 끝나는 시간을 기준으로 정렬
  sort(list.begin(), list.end());

  int count = 1;
  int endTime = list[0][0];
  for (int i=1; i<n; i++) {

    // 시작 시간이 이전 회의 끝나는 시각보다 늦으면 ㅇㅋ
    if (endTime <= list[i][1]) {
      count++;
      endTime = list[i][0];
    }
  }

  cout << count;
  return 0;
}