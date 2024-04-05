#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int dir = 1;
int b[1005][1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int c, r;
	cin >> c >> r;
	int k;
	cin >> k;
	if (r * c < k)
	{
		cout << 0;
		return 0;
	}
	int cur = 1;
	int x = 0;
	int y = r - 1;
	b[y][x] = cur;
	while (cur < k)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= c || ny >= r || b[ny][nx] != 0)
		{
			dir = (dir + 1) % 4;
			nx = x + dx[dir];
			ny = y + dy[dir];
		}
		b[ny][nx] = ++cur;
		x = nx;
		y = ny;
	}

	cout << x+1 << ' ' << r-y;
	

	return 0;
}