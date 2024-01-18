#include <bits/stdc++.h>

using namespace std;

int dp[100005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	fill(dp, dp + 100005, 0x3f3f3f3f);
	for (int k = 1; k * k <= n; k++)
	{
		dp[k * k] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int k = 1; k * k <= i; k++)
		{
			dp[i] = min(dp[i], dp[i - k * k] + 1);
		}
	}
	cout << dp[n];

	return 0;
}

