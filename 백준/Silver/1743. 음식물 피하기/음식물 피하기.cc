#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int b[105][105];
bool v[105][105];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int n, m, k;

int bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	int sz = 0;
	v[y][x] = true;
	while (!q.empty())
	{
		auto [cx, cy] = q.front();
		q.pop();
		sz++;
		for (int i = 0; i < 4; i++)
		{
			int tx = cx + dx[i];
			int ty = cy + dy[i];
			if (tx < 0 || ty < 0 || tx >= m || ty >= n)continue;
			if (b[ty][tx] == 0 || v[ty][tx]) continue;
			q.push({ tx,ty });
			v[ty][tx] = true;
		}
	}
	return sz;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		int r, c;
		cin >> r >> c;
		b[r-1][c-1] = 1;
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (b[i][j] == 1 && !v[i][j])
				ans = max( ans, bfs(j, i));
		}
	}
	cout << ans;

	return 0;
}