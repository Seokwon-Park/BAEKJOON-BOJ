#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int b[16][16];
int dp[16][16];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	dp[1][1] = 1;
	if (k == 0)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
			}
		}
		cout << dp[n][m];
	}
	else
	{
		k--;
		int my = k / m + 1;
		int mx = k % m + 1;
		for (int i = 1; i <= my; i++)
		{
			for (int j = 1; j <= mx; j++)
			{
				dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
			}
		}

		for (int i = my; i <= n; i++)
		{
			for (int j = mx; j <= m; j++)
			{
				if (i == my && j == mx) continue;
				dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
			}
		}
		cout << dp[n][m];
	}


	return 0;
}