#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int n;
int w[16][16];
int dp[16][1 << 16];

int dfs(int cur, int visited)
{
	if (visited == (1 << n) - 1)
	{
		if (w[cur][0] == 0) return INF;
		else return w[cur][0];
	}

	if (dp[cur][visited] != -1) return dp[cur][visited];
	dp[cur][visited] = INF;

	for (int i = 0; i < n; i++)
	{
		if (w[cur][i] == 0) continue;
		if (visited & (1 << i)) continue;
		dp[cur][visited] = min(dp[cur][visited], w[cur][i] + dfs(i, visited | (1 << i)));
	}
	return dp[cur][visited];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n*n; i++)
	{
		cin >> w[i / n][i % n];
	}

	for (int i = 0; i < n; i++)
	{
		fill(dp[i], dp[i] + (1 << 16), -1);
	}

	cout <<	dfs(0, 1);

	return 0;
}