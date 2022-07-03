#include <iostream>
#include <vector>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);

  int n, pair;
  cin >> n >> pair;

  int tmp1, tmp2;
  vector<vector<int>> friends(n+1, vector<int>(0, 0));

  /* 인접 리스트 생성
    friends[1] = {2, 3}
    friends[2] = {1, 3}
    friends[3] = {1, 2, 4}
    friends[4] = {3 ,5}
    friends[5] = {4}
    */
  for (int i=0; i<pair; i++) {
    cin >> tmp1 >> tmp2;
    friends[tmp1].push_back(tmp2);
    friends[tmp2].push_back(tmp1);
  }

  vector<int> visited (n+1, 0);

  int cnt = 0;
  visited[1] = 1;

  // 일단 나랑 친구여야대니까 1이랑 연결되어있는 애들부터
  for (int f : friends[1]) {
    if (!visited[f]) {
      visited[f] = 1;
      cnt++;
    }
    // 내 친구의 친구도 되니까 한번 더 ㄱ
    for (int ff : friends[f]) {
      if (!visited[ff]) {
        visited[ff] = 1;
        cnt++;
      }
    }
  }
  cout << cnt;
  
  return 0;
}