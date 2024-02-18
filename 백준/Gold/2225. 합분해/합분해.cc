#include <bits/stdc++.h>

using namespace std;

long long dp[205][205];

#define MOD 1000000000

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i <= n; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= k; i++)
	{
		for (int a = 0; a <= n; a++)
		{
			for (int b = 0; b <= a; b++)
			{
				dp[i][a] += dp[i - 1][b];
				dp[i][a] %= MOD;
			}
		}
	}

	cout << dp[k][n];

	return 0;
}