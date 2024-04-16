#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int b[55][55];
int dist[55][55];
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,-1,-1,0,1,1,-1 };

queue<pair<int, int>> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
			if (b[i][j] == 1)
				q.push({ j,i });
		}
	}

	
	while (!q.empty())
	{
		int qs = q.size();
		for (int k = 0; k < qs; k++)
		{
			auto [x, y] = q.front();
			q.pop();
			for (int i = 0; i < 8; i++)
			{
				int tx = x + dx[i];
				int ty = y + dy[i];
				if (tx < 0 || ty < 0 || tx >= m || ty >= n) continue;
				if (b[ty][tx] == 1) continue;
				if (dist[ty][tx])
				{
					if (dist[y][x] + 1 >= dist[ty][tx])continue;
				}
				dist[ty][tx] = dist[y][x] + 1;
				q.push({ tx,ty });
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ans = max(ans, dist[i][j]);
		}
	}

	cout << ans;

	return 0;
}