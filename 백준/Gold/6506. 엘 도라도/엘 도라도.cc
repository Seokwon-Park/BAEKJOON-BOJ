#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

ll dp[105][105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;

	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)break;
		vector<int> v(n + 1);
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++)
		{
			cin >> v[i];
			dp[1][i] = 1;
		}

		for (int i = 2; i <= m; i++)
		{
			for (int j = i; j <= n; j++)
			{
				for (int k = 1; k <= j; k++)
				{
					if (v[k] < v[j])
						dp[i][j] += dp[i - 1][k];
				}
			}
		}

		ll ans = 0;
		for (int i = 1; i <= n; i++)
		{
			ans += dp[m][i];
		}
		cout << ans << '\n';
	}


	return 0;
}