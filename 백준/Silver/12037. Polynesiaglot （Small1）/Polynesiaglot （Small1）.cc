#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

ll dp[16][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int x = 1; x <= tc; x++)
	{
		for (int i = 0; i < 16; i++)
		{
			fill(dp[i], dp[i] + 2, 0);
		}
		ll c, v, l;
		cin >> c >> v >> l;

		dp[1][0] = c;
		dp[1][1] = v;
		for (int i = 1; i < l; i++) {
			dp[i + 1][1] = ((dp[i][0] + dp[i][1]) * v) % MOD;
			dp[i + 1][0] = (dp[i][1] * c) % MOD;
		}
		cout << "Case #" << x << ": ";
		cout << dp[l][1]% MOD << '\n';
	}


	return 0;
}