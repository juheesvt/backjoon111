#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);

  int n;
  priority_queue<int, vector<int>, greater<int>> pq; //최솟값이 루트로 가는 우선순위큐
  vector<pair<int, int>> univ; //d, p 저장 벡터
  int result = 0;

  cin >> n;
  for (int i = 0; i < n; i++) {
    int p, d;
    cin >> p >> d;
    univ.emplace_back(d, p); //day 순으로 정렬
  }
 
  sort(univ.begin(), univ.end());
 
  for (int i = 0; i < n; i++) {
    pq.push(univ[i].second);
    result += univ[i].second;
 
    if (pq.size() > univ[i].first) {
      result -= pq.top();
      pq.pop();
    }
  }
    
  cout << result;
 
  return 0;

}