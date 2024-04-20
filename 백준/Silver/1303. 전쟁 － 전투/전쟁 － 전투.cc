#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

char b[105][105];
bool v[105][105];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int n, m;


int bfs(int x, int y, char team)
{
	queue<pii> q;
	q.push({ x,y });
	v[y][x] = true;
	int area = 0;
	while (!q.empty())
	{
		auto [cx, cy] = q.front();
		area++;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = cx + dx[i];
			int ty = cy + dy[i];
			if (tx < 0 || ty < 0 || tx >= n || ty >= m)continue;
			if (v[ty][tx] || b[ty][tx] != team) continue;
			q.push({ tx,ty });
			v[ty][tx] = true;
		}
	}
	return area;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
		}
	}

	ll ww = 0;
	ll bb = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (b[i][j] == 'W' && !v[i][j])
			{
				int res = bfs(j, i, 'W');
				ww += res * res;
			}
			if (b[i][j] == 'B' && !v[i][j])
			{
				int res = bfs(j, i, 'B');
				bb += res * res;
			}
		}
	}

	cout << ww << ' ' << bb;



	return 0;
}