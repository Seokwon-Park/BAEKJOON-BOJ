#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int r, c;
char b[105][105];
bool v[105][105];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

void bfs(int xx, int yy)
{
	queue<pii> q;
	q.push({ xx,yy });
	v[yy][xx] = 1;
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx < 0 || ty < 0 || tx >= c || ty >= r)continue;
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
	
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> b[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (b[i][j] == '#' && !v[i][j])
			{
				bfs(j, i);
				ans++;
			}
		}
	}
	cout << ans;

	return 0;
}