#include <bits/stdc++.h>

using namespace std;

int dp[1000005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	dp[1] = 1;
	dp[2] = 2;

	int n;
	cin >> n;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] % 15746)+ (dp[i - 2]%15746);
	}
	
	cout << dp[n] % 15746 ;

	return 0;
}