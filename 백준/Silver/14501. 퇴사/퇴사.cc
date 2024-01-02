#include <bits/stdc++.h>

using namespace std;

int dp[25];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> ti(25);
	vector<int> pi(25);

	for (int i = 1; i <= n; i++)
	{
		cin >> ti[i] >> pi[i];
	}
	// dp[i] : i일차부터 일했을 때 얻을 수 있는 최대 이득
	for (int i = n; i >= 1; i--)
	{
		if (i + ti[i] > n + 1)
		{
			dp[i] = dp[i + 1];
		}
		else
		{
			dp[i] = max(dp[i + 1], dp[i + ti[i]] + pi[i]);
		}
	}

	cout << dp[1];

		
	return 0;
}