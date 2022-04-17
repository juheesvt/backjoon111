#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    vector<int> num;
    int tmp;
    
    for (int i; i<n; i++){
        cin >> tmp;
        num.push_back(tmp);
    }
    
    sort(num.begin(), num.end());
    
    int sum = num[0];
    vector<int> cash;
    
    cash.push_back(num[0]);
    for(int i=1; i<n; i++){
        cash.push_back(cash[i-1]+num[i]);
        sum += cash[i];

    }
    cout << sum;
    return 0;
    
}