#include <bits/stdc++.h>

using namespace std;

int dp[100005][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < 3; i++)
	{
		dp[1][i] = 1;
	}

	for (int j = 2; j <= n; j++)
	{
		dp[j][0] = (dp[j - 1][0] + dp[j - 1][1] + dp[j - 1][2])%9901;
		dp[j][1] = (dp[j - 1][0] + dp[j - 1][2]) % 9901;
		dp[j][2] = (dp[j - 1][0] + dp[j - 1][1]) % 9901;
	}

	cout << (dp[n][0] + dp[n][1] + dp[n][2]) % 9901;



	return 0;
}
