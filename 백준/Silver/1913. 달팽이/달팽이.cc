#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int b[1005][1005];
bool visited[1005][1005];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int dir = 3;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	int cur = n * n;
	int x = 0, y = -1;
	int ansx, ansy;
	while (cur > 0)
	{
		int tx = x + dx[dir];
		int ty = y + dy[dir];
		if (tx < 0 || ty < 0 || tx >= n || ty >= n ||b[ty][tx] != 0)
		{
			dir = (dir + 3) % 4;
			tx = x + dx[dir];
			ty = y + dy[dir];
		}
		x = tx;
		y = ty;
		if (cur == k)
		{
			ansy = y;
			ansx = x;
		}
		b[y][x] = cur--;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << b[i][j]<< ' ';
		cout << '\n';
	}
	cout << ansy + 1 << ' ' << ansx + 1;

	return 0;
}
