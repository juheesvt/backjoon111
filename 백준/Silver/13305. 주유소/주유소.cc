#include <iostream>
#include <vector>

using namespace std;

int main() {

  int n, tmp;
  cin >> n;

  vector<long long> city;
  vector<long long> distance;

  for (int i=0; i<n-1; i++) {
    cin >> tmp;
    distance.push_back(tmp);
  }
  
  for (int i=0; i<n; i++) {
    cin >> tmp;
    city.push_back(tmp);
  }

  long long min = city[0];
  long long amount = min * distance[0];

  for (int i=1; i<n-1; i++) {
    if (min > city[i])
      min = city[i];
    amount += min * distance[i];
  }

  cout << amount;
  
  return 0;
}