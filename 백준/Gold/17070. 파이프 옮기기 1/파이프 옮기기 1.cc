#include <bits/stdc++.h>

using namespace std;

int n;
int dp[3][20][20]; // 0 : ㅡ , 1 : \ , 2 : ㅣ
int board[20][20];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> board[i][j];
		}
	}

	dp[0][1][2] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 3; j <= n; j++)
		{
			if (board[i][j] == 1) continue;
			dp[0][i][j] = dp[1][i][j - 1] + dp[0][i][j-1];
			if(board[i-1][j] == 0 && board[i][j-1] == 0)
			{ 
				dp[1][i][j] = dp[0][i - 1][j - 1] + dp[1][i - 1][j - 1] + dp[2][i - 1][j - 1];
			}
			dp[2][i][j] = dp[2][i - 1][j] + dp[1][i - 1][j];
		}
	}

	cout << dp[0][n][n] + dp[1][n][n] + dp[2][n][n];

	return 0;
}