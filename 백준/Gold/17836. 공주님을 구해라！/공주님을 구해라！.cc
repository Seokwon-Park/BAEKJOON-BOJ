#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int n, m, t;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int b[105][105];
int dist[105][105];
bool v[105][105];

int bfs()
{
	queue<pii> q;
	q.push({ 0,0 });
	v[0][0] = 1;
	int d = 0;
	//일단 그냥 가는 방법
	bool findGram = false;
	bool fin = false;
	int gx, gy;
	int dNoGram = 0x3f3f3f;
	int dGram = 0x3f3f3f;
	while (!q.empty())
	{
		d++;
		int qs = q.size();
		for (int j = 0; j < qs; j++)
		{
			auto [x, y] = q.front();
			q.pop();
			if (y == n - 1 && x == m - 1) // 그냥 가서 도달한 경우
			{
				dNoGram = min(dNoGram, dist[y][x]);
			}
			for (int i = 0; i < 4; i++)
			{
				int tx = x + dx[i];
				int ty = y + dy[i];
				if (tx < 0 || ty < 0 || tx >= m || ty >= n) continue;
				if (b[ty][tx] == 1 || v[ty][tx]) continue;

				q.push({ tx,ty });
				dist[ty][tx] = d;
				v[ty][tx] = true;

				if (b[ty][tx] == 2)
				{
					findGram = true;
					gx = tx;
					gy = ty;
					dGram = dist[ty][tx];
				}
			}
		}
	}

	if (findGram)
		dGram += (m - 1 - gx) + (n - 1 - gy);

	return min(dGram, dNoGram);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> t;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
			dist[i][j] = 0x3f3f3f;
		}
	}

	int res = bfs();
	if (res <= t)
	{
		cout << res;
	}
	else
	{
		cout << "Fail";
	}

	//cout << '\n';
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		if (dist[i][j] == 0x3f3f3f)
	//			cout << 'X' << ' ';
	//		else
	//			cout << dist[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}

	return 0;
}