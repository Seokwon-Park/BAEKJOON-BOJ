#include <bits/stdc++.h>

using namespace std;

int dp[100005][2];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	//dp[i][j] : j줄 i번째 스티커를 뗐을때의 최대값?
	while (tc--)
	{
		int n;
		cin >> n;

		int board[100005][2];

		for (int i = 0; i <= n; i++)
		{
			fill(dp[i], dp[i] + 2, 0);
		}
		for (int i = 0; i < 2; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> board[j][i];
			}
		}
		dp[1][0] = board[1][0];
		dp[1][1] = board[1][1];

		for (int j = 2; j <= n; j++)
		{
			for (int i = 0; i < 2; i++)
			{
				dp[j][i] = max(dp[j - 1][!i], dp[j - 2][!i]) + board[j][i];
			}
		}

		cout << max(dp[n][0],dp[n][1]) << '\n';
	}





	return 0;
}