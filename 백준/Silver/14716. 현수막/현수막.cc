#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int b[255][255];
bool v[255][255];
int dx[8] = { -1,0,1,0, -1,-1, 1,1 };
int dy[8] = { 0,-1,0,1, - 1, 1,1,-1 };
int m, n;

void bfs(int x, int y)
{
	queue<pii> q;
	q.push({ x,y });
	v[y][x] = true;
	while (!q.empty())
	{
		auto [cx, cy] = q.front();
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int tx = cx + dx[i];
			int ty = cy + dy[i];
			if (tx < 0 || ty < 0 || tx >= n || ty >= m) continue;
			if (v[ty][tx] || b[ty][tx] == 0)continue;
			q.push({ tx,ty });
			v[ty][tx] = true;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (b[i][j] == 1 && !v[i][j])
			{
				bfs(j, i);
				ans++;
			}
		}
	}

	cout << ans;

	return 0;
}