#include <iostream>
#include<stack>
#include<string>
using namespace std;
 
int main() {
	string S; // 문자열 S
	getline(cin, S);
	S += ' ';
 
	stack<char> s;
 
	string result; // 결과물
 
	int i = 0;
	int cnt = S.length();
 
	while (i <= cnt)
	{
		if (S[i] == '<')
		{
			if (!s.empty())
			{
				while (!s.empty()) {
					result += s.top();
					s.pop();
				}
				result += '<';
				i++;
			}
			
			while (S[i] != '>')
			{
				result += S[i++];
			}
			result += S[i++];
		}
		else
		{
			s.push(S[i]);
 
			if (S[i] == ' ')
			{
				s.pop();				
				while (!s.empty())
				{
					result += s.top();
					s.pop();
				}
				result += ' ';
			}
			i++;
 
		}
	}
 
	for (int k = 0; k < cnt; k++)
	{
		cout << result[k];
	}
 
	return 0;
}