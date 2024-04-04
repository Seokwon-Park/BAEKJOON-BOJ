#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int dp[15];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	dp[1] = 0;
	dp[2] = 1;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i / 2] + dp[i - (i / 2)] + (i / 2 * (i - i / 2));
	}
	cout << dp[n];
	
	return 0;
}