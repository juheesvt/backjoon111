#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

  int len;
  cin >> len;

  vector<int> a;
  vector<int> b;

  int tmp;
  for (int i=0; i<len; i++) {
    cin >> tmp;
    a.push_back(tmp);
  }

  for (int i=0; i<len; i++) {
    cin >> tmp;
    b.push_back(tmp);
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int result = 0;
  for (int i=0; i<len; i++) {
    result += a[i]*b[len-i-1];
  }

  cout << result;
  return 0;
}