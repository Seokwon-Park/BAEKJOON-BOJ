#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int dp[25][205];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<pii> v(m+1);
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[i] = { a,b };
	}

	for (int i = 1; i <= m; i++)
	{
		auto [d, w] = v[i];
		for(int j = 1; j <= n; j++)
		{
			if (d > j)
			{
				dp[i][j] = dp[i-1][j];
			}
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i - 1][j - d] + w);
			}
		}
	}

	cout << dp[m][n];

	return 0;
}