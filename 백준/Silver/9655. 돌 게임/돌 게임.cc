#include <bits/stdc++.h>

using namespace std;

int dp[1005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	dp[1] = 's';
	dp[2] = 'c';
	dp[3] = 's';
	dp[4] = 'c';
	
	for (int i = 5; i <= n; i++)
	{
		if (dp[i - 1] == 's' || dp[i - 3] == 's')
			dp[i] = 'c';
		else
			dp[i] = 's';
	}

	if (dp[n] == 's')
	{
		cout << "SK";
	}
	else
		cout << "CY";

	return 0;
}