#include <bits/stdc++.h>

using namespace std;

int dp[1005][35][3];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t, w;
	cin >> t >> w;

	vector<vector<int>> arr(t + 1, vector<int>(3, 0));
	for (int i = 1; i <= t; i++)
	{
		int tree;
		cin >> tree;
		arr[i][tree] = 1;
	}

	int answer = 0;

	for (int i = 1; i <= t; i++)
	{
		dp[i][0][1] = dp[i - 1][0][1] + arr[i][1];
		for (int j = 1; j <= w; j++)
		{
			dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][2]) + arr[i][1];
			dp[i][j][2] = max(dp[i - 1][j][2], dp[i - 1][j - 1][1]) + arr[i][2];
		}
	}

	cout << max(dp[t][w][1], dp[t][w][2]);;

	return 0;
}
