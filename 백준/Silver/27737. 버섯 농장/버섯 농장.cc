#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int n, m, k;
int b[105][105];
int v[105][105];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int bfs(pii xy)
{
	queue<pii> q;
	q.push(xy);
	v[xy.second][xy.first] = 1;
	int visited = 0;
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		visited++;
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx < 0 || ty < 0 || tx >= n || ty >= n)continue;
			if (v[ty][tx] || b[ty][tx] == 1) continue;
			q.push({ tx,ty });
			v[ty][tx] = true;
		}
	}
	return visited;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
		}
	}

	int mm = m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!v[i][j] && b[i][j] == 0)
			{
				int res = bfs({ j,i });
				m -= res / k + (res % k != 0 ? 1 : 0);

			}
		}
	}
	
	if (m < 0 || mm == m)
	{
		cout << "IMPOSSIBLE";
	}
	else
	{
		cout << "POSSIBLE\n";
		cout << m;
	}
	return 0;
}