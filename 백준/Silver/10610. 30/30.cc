#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  string n;
  cin >> n;

  // string을 vector로 바꾸는 방법
  vector<char> v(n.begin(), n.end());
  sort(v.begin(), v.end());

  if (v[0] != '0') {
    cout << -1;
  }

  else {
    long long sum = 0;
    for (long long i=1; i<v.size(); i++) {
      sum += v[i]-48;
    }
    
    if (sum % 3 == 0) {
      for (long long i=v.size()-1; i>=0; i--) {
        cout << v[i];
      }
    }
    else {
      cout << -1;
    }
  }

  
    return 0;
}