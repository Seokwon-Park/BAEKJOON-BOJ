#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

ll dp[100005][10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i < 10; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			for (int k = max(1, j - 2); k <= min(9, j + 2); k++)
			{
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= 987654321;
			}
		}
	}

	ll ans = 0;
	for (int i = 1; i <= 9; i++)
	{
		ans += dp[n][i];
		ans %= 987654321;
	}
	cout << ans;

	return 0;
}



