#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int dp[105][10005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, t;
	cin >> n >> t;
	vector<pii> v(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int k, s;
		cin >> k >> s; 
		v[i] = make_pair(k, s);
	}

	for (int i = 1; i <= n; i++)
	{
		auto [k, s] = v[i];
		for (int j = 0; j <= t; j++)
		{
			if (j >= k)
			{
				dp[i][j] = max(dp[i-1][j], dp[i - 1][j - k] + s);
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	cout << dp[n][t];



	return 0;
}
