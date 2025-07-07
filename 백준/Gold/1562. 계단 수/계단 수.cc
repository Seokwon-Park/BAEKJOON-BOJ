#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;


int dp[105][10][1 << 10];



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i < 10; i++)
	{
		dp[1][i][1 << i] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < (1 << 10); k++)
			{
				if (dp[i][j][k] == 0) continue;
				if (j - 1 >= 0)
				{
					dp[i + 1][j - 1][k | (1 << (j - 1))] += dp[i][j][k];
					dp[i + 1][j - 1][k | (1 << (j - 1))] %= MOD;
				}
				if (j + 1 < 10)
				{
					dp[i + 1][j + 1][k | (1 << (j + 1))] += dp[i][j][k];
					dp[i + 1][j + 1][k | (1 << (j + 1))] %= MOD;
				}
			}
		}
	}

	ll res = 0;
	for (int i = 0; i < 10; i++)
	{
		res += dp[n][i][(1 << 10) - 1];
		res %= MOD;
	}
	cout << res;

	return 0;
}