#include <bits/stdc++.h>

using namespace std;

long long dp[105][105];
int board[105][105];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}

	dp[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == n - 1 && j == n - 1)break;
			if (dp[i][j] != 0)
			{
				dp[i + board[i][j]][j] += dp[i][j];
				dp[i][j + board[i][j]] += dp[i][j];

				//cout << endl;
				//for (int x = 0; x < n; x++)
				//{
				//	for (int y = 0; y < n; y++)
				//	{
				//		cout << dp[x][y] << ' ';
				//	}
				//	cout << endl;
				//}
			}
		}
	}

	cout << dp[n - 1][n - 1];


	return 0;
}