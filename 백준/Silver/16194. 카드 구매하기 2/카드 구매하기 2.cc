#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

ll dp[1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int > v(n+1);
	for (int i = 1; i<=n; i++)
		cin >> v[i];

	fill(dp, dp + n + 1, 1e18);
	dp[0] = 0;
	dp[1] = v[1];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = min(dp[i], dp[i - j] + v[j]);
		}
	}

	cout << dp[n];

	return 0;
}
