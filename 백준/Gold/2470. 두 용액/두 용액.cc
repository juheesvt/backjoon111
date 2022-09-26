#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> numbers (n, 0);
    for (int i=0; i<n; i++) {
      cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());

    int l = 0, r = n-1;
    pair<int, int> result = {numbers[l], numbers[r]};
    
    while (l < r){

      int resultSum = abs(result.first + result.second);
      if (abs(numbers[l]+numbers[r]) < resultSum) {
        result.first = numbers[l];
        result.second = numbers[r];
        }
      
      
      if (numbers[l] + numbers[r] < 0) {
        l += 1;
      } else if (numbers[l] + numbers[r] > 0) {
        r -= 1;
      } else {
        result.first = numbers[l];
        result.second = numbers[r];
        break;
      }

  }      
  cout << result.first << " " << result.second;
      return 0;
  }