#include <bits/stdc++.h>

using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int tc;
	cin >> tc;

	while (tc--)
	{

		int n;
		cin >> n;
		vector<int> coins(n);
		for (int i = 0; i < n; i++)
			cin >> coins[i];
		int k;
		cin >> k;
		vector<int> dp(k + 5, 0);
		dp[0] = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = coins[i]; j <= k; j++)
			{
				dp[j] += dp[j - coins[i]];
			} 
		}

		cout << dp[k] << '\n';
	}

	return 0;
}