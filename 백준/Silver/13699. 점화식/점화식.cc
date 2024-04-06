#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll dp[36];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	dp[0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= i - 1; j++)
		{
			dp[i] += dp[j] * dp[i - 1 - j];
		}
	}
	cout << dp[n];

	return 0;
}