#include<iostream>
#include<string>
using namespace std;

int endFlag = 0;
int N;

bool isValid(string result) {
	int len = result.size();
	int end = len - 1;

	for (int i = 1; i <= len / 2; i++) {
		string a = result.substr(end - i, i);
		string b = result.substr(end, i);
		if (!a.compare(b)) return false;
		--end;
	}
	return true;
}

void dfs(int step, string result) {
	if (endFlag == 1) return; //처음 만난 이후 flag=1이므로 출력 x
	if (!isValid(result)) return; //가지치기 조건
	if (step == N) {
		cout << result << '\n'; //처음 만나면 출력
		endFlag = 1;
		return;
	}
	dfs(step + 1, result + '1');
	dfs(step + 1, result + '2');
	dfs(step + 1, result + '3');
}
int main() {

	cin >> N;
	dfs(0, "");

	return 0;
}