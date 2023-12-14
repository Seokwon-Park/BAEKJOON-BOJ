#include <bits/stdc++.h>

using namespace std;

long long dp[105];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> tc(n);

	for (int i = 0; i < n; i++)
	{
		cin >> tc[i];
	}

	int dp_range = *max_element(tc.begin(), tc.end());

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;

	for (int i = 6; i <= dp_range; i++)
	{
		dp[i] = dp[i - 5] + dp[i - 1];
	}

	for (auto t : tc)
	{
		cout << dp[t] << '\n';
	}

	return 0;
}