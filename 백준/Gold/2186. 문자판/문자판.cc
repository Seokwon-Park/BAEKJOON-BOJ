#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int n, m, k;
char b[105][105];
string word;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int dp[105][105][85];

int dfs(int x, int y, int ix)
{
	if (b[y][x] != word[ix])
		return 0;

	if (ix == word.size()-1)
		return 1;

	if (dp[y][x][ix] != -1)
	{
		return dp[y][x][ix];
	}
	dp[y][x][ix] = 0;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int tx = x + dx[j] * i;
			int ty = y + dy[j] * i;
			if (tx < 0 || ty < 0 || tx >= m || ty >= n) continue;
			dp[y][x][ix] += dfs(tx, ty, ix + 1);
		}
	}
	return dp[y][x][ix];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			fill(dp[i][j], dp[i][j] + 80, -1);
			cin >> b[i][j];
		}
	}

	cin >> word;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ans += dfs(j, i, 0);
		}
	}

	cout << ans;


	return 0;
}
