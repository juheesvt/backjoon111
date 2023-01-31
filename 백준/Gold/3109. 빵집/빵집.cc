	#include <iostream>
#include <string>
using namespace std;
 
int r, c;
string map[10000];
bool visited[10000][500] = { false, };
int ret = 0;
const int dx[] = { 1,1,1 };
const int dy[] = { -1,0,1 };
 
 
bool dfs(int cy, int cx)
{
	visited[cy][cx] = true;
	if (cx == c - 1)
	{
		ret++;
		return true;
	}
 
	for (int dir = 0; dir < 3; ++dir)
	{
		int nx = cx + dx[dir];
		int ny = cy + dy[dir];
 
		if (ny < 0 || ny >= r || visited[ny][nx]|| map[ny][nx] == 'x')
			continue;
 
		if (dfs(ny, nx))
			return true;
	}
	return false;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> r >> c;
	
	for (int i = 0; i < r; ++i)
		cin >> map[i];
 
	for (int i = 0; i < r; ++i)
		dfs(i, 0);
	
	cout << ret;
 
	return 0;
}