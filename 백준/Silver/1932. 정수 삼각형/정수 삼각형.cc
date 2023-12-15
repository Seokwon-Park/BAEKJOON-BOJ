#include <bits/stdc++.h>

using namespace std;

int tri[505][505];
int dp[505][505];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cin >> tri[i][j];
		}
	}

	dp[0][0] = tri[0][0];

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i-1][j] + tri[i][j];
			}
			else if (j == i)
			{
				dp[i][j] = dp[i - 1][j - 1] + tri[i][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j - 1] + tri[i][j], dp[i - 1][j] + tri[i][j]);
			}
		}
	}

	cout << *max_element(dp[n - 1], dp[n - 1] + n);

	return 0;
}