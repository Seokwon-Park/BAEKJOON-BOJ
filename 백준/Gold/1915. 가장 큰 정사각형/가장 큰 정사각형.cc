#include <bits/stdc++.h>

using namespace std;

int board[1005][1005];
int dp[1005][1005];
int n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int max_sq = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			board[i][j] = c - '0';
			if (i == 0 || j == 0)
			{
				dp[i][j] = board[i][j];
				max_sq = max(max_sq, dp[i][j]);
			}
		}
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if(board[i][j] == 1)
			dp[i][j] = min({ dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1] }) + 1;
			max_sq = max(max_sq, dp[i][j]);
		}
	}

	cout << max_sq * max_sq;

	return 0;
}
