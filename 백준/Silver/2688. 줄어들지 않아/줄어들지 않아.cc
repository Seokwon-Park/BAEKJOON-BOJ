#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

ll dp[1005][10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	fill(dp[1], dp[1] + 10, 1);

	for (int i = 2; i <= 1000; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j; k++)
				dp[i][j] += dp[i - 1][k];
		}
	}

	int tc;
	cin >> tc;
	while (tc--)
	{
		ll ans = 0;
		int n;
		cin >> n;
		for (int i = 0; i < 10; i++)
		{
			ans += dp[n][i];
		}
		cout << ans << '\n';
	}

	return 0;
}