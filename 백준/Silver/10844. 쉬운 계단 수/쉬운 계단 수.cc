#include <bits/stdc++.h>

#define MOD 1000000000
using namespace std;

long long dp[105][10];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	// 1자리 수일때
	for (int i = 1; i < 10; i++)
	{
		dp[1][i] = 1;
	}
	dp[1][0] = 0;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if(j == 0)
			{
				dp[i][j] = (dp[i - 1][1]) % MOD;
			}
			else if (j == 9)
			{
				dp[i][j] = (dp[i-1][8]) %MOD;
			}
			else
			{
				dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
			}
		}
	}

	long long sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum = (sum +dp[n][i])% MOD;
	}

	cout << sum;


	return 0;
}