#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int avg[1005][1005];
int b[1005][1005];
bool v[1005][1005];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int n, m;

void bfs(int x, int y)
{
	queue<pii> q;
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
			if (tx < 0 || ty < 0 || tx >= m || ty >= n)continue;
			if (b[ty][tx] == 0 || v[ty][tx])continue;
			q.push({ tx,ty });
			v[ty][tx] = true;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int r, g, b;
			cin >> r >> g >> b;
			avg[i][j] = (r + g + b) / 3;
		}
	}
	int t;
	cin >> t;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (avg[i][j] >= t)
				b[i][j] = 1;
		}
	}


	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
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