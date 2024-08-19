#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int n, m;
char b[505][505];
bool v[505][505];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int dp[505][505];

int dfs(int x, int y)
{
	if (x < 0 || y < 0 || x >= m || y >= n)
		return 1;
	if (dp[y][x] != -1)
	{
		return dp[y][x];
	}
	if (v[y][x])
		return 0;
	int dir;
	if (b[y][x] == 'U') dir = 1;
	else if (b[y][x] == 'R') dir = 2;
	else if (b[y][x] == 'D') dir = 3;
	else dir = 0;
	int tx = x + dx[dir];
	int ty = y + dy[dir];
	v[y][x] = true;
	return dp[y][x] = dfs(tx, ty);
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
			dp[i][j] = -1;
			cin >> b[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ans += dfs(j, i);
		}
	}

	cout << ans;


	return 0;
}
