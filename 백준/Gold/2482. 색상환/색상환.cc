#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000003

long long dp[1005][1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		dp[i][1] = i;
	}

	for (int i = 4; i <= n; i++)
	{
		for (int j = 2; j <= k; j++)
		{
			if (j > i / 2) continue;
			dp[i][j] = (dp[i - 1][j] + dp[i - 2][j-1])% MOD;
		}
	}
	cout << dp[n][k];

	return 0;
}