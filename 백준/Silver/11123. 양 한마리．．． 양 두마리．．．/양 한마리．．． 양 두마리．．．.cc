#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

char b[105][105];
bool v[105][105];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int h, w;

void reset()
{
	for (int i = 0; i < h; i++)
		fill(v[i], v[i] + w, false);
}

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	v[y][x] = true;
	while (!q.empty())
	{
		auto [cx, cy] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = cx + dx[i];
			int ty = cy + dy[i];
			if (tx < 0 || ty < 0 || tx >= w || ty >= h) continue;
			if (v[ty][tx] || b[ty][tx] == '.')continue;
			q.push({ tx,ty });
			v[ty][tx] = true;
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		reset();
		cin >> h >> w;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> b[i][j];
			}
		}

		int ans = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (b[i][j] == '#' && !v[i][j])
				{
					bfs(j, i);
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}


	return 0;
}
