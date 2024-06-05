#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int n;
int b[505][505];
int dp[505][505];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int dfs(int x, int y)
{
	if (dp[y][x] != 0) return dp[y][x];
	dp[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 0 || ty < 0 || tx >= n || ty >= n)continue;
		if (b[ty][tx] <= b[y][x]) continue;
		dp[y][x] = max(dfs(tx, ty) + 1, dp[y][x]);
	}
	return dp[y][x];
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ans = max(dfs(j, i), ans);
		}
	}

	cout << ans;

	return 0;
}