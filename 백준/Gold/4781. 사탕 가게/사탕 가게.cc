#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
int dp[5005][10005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (1)
	{
		int n;
		double m;
		cin >> n >> m;
		if (n == 0 && m == 0.0) break;
		vector<pii> v;
		for (int i = 0; i < n; i++)
		{
			int a;
			double b;
			cin >> a >> b;
			int tmp = (b * 100.0+0.5);
			v.push_back({ a, tmp });
		}
		int currency = m * 100 +0.5;
		for (int i = 1; i <= n; i++)
		{
			auto [value, cost] = v[i - 1];
			for (int j = 1; j <= currency; j++)
			{
				dp[i][j] = dp[i - 1][j];
				if (j >= cost)
				{
					dp[i][j] = max(dp[i][j], dp[i][j - cost] + value);
				}
			}
		}
		cout << dp[n][currency] << '\n';


	}

	return 0;
}

