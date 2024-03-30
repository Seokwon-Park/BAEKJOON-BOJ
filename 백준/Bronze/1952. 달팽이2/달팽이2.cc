#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
bool b[105][105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n;
	cin >> m >> n;
	int turn = 0;
	int dir = 2;
	int visited = 1;
	b[0][0] = true;
	int x = 0;
	int y = 0;
	while (visited < m * n)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m || b[ny][nx])
		{
			dir = (dir + 1) % 4;
			turn++;
			continue;
		}
		x = nx;
		y = ny;
		visited++;
		b[ny][nx] = true;
	}
	
	cout << turn;

	return 0;
}