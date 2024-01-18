#include <bits/stdc++.h>

using namespace std;

int dp[100005][4];
int graph[100005][4];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int tc = 0;
	while (++tc)
	{
		int n;
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++)
		{
			cin >> graph[i][1] >> graph[i][2] >> graph[i][3];
		}
		dp[0][1] = 0x3f3f3f3f;
		dp[0][2] = graph[0][2];
		dp[0][3] = dp[0][2]+graph[0][3];
		for (int i = 1; i < n; i++)
		{
			dp[i][1] = min(dp[i - 1][1], dp[i - 1][2])+graph[i][1];
			dp[i][2] = min({ dp[i][1],dp[i - 1][1], dp[i - 1][2], dp[i - 1][3] }) + graph[i][2];
			dp[i][3] = min({ dp[i][2], dp[i - 1][2], dp[i - 1][3] }) + graph[i][3];
		}

		cout << tc << ". " << dp[n - 1][2] << '\n';
	}

	return 0;
}
