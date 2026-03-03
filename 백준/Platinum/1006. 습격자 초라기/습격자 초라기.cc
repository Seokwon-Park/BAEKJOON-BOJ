#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int n, w;
int dp[10005][3]; // 0:바깥채움 1:안쪽채움 2:양쪽채움
int v1[10005];
int v2[10005];

void clear()
{
	for (int i = 0; i <= n; i++)
		fill(dp[i], dp[i] + 3, INF);
}
void func()
{
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][2] + 1;
		if (v1[i - 1] + v1[i] <= w)
		{
			dp[i][0] = min(dp[i][0], dp[i - 1][1] + 1);
		}

		dp[i][1] = dp[i - 1][2] + 1;
		if (v2[i - 1] + v2[i] <= w)
		{
			dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
		}

		dp[i][2] = min({ dp[i][0] + 1,dp[i][1] + 1, dp[i - 1][2] + 2 });
		if (v1[i] + v2[i] <= w)
		{
			dp[i][2] = min(dp[i][2], dp[i - 1][2] + 1);
		}
		if (v1[i - 1] + v1[i] <= w && v2[i - 1] + v2[i] <= w)
		{
			dp[i][2] = min(dp[i][2], dp[i - 2][2] + 2);
		}

	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int ans = INF;

		cin >> n >> w;
		for (int i = 1; i <= n; i++)
		{
			cin >> v1[i];
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> v2[i];
		}
		clear();
		dp[0][0] = 0;
		dp[0][1] = 0;
		dp[0][2] = 0;
		dp[1][0] = 1;
		dp[1][1] = 1;
		dp[1][2] = (v1[1] + v2[1] <= w ? 1 : 2);
		func();
		ans = min(ans, dp[n][2]);

		if (n > 1)
		{
			if (v1[1] + v1[n] <= w)
			{
				clear();
				dp[1][0] = 1;
				dp[1][1] = INF;
				dp[1][2] = 2;
				func();

				ans = min(ans, dp[n][1]);
			}

			if (v2[1] + v2[n] <= w)
			{
				clear();
				dp[1][0] = INF;
				dp[1][1] = 1;
				dp[1][2] = 2;
				func();

				ans = min(ans, dp[n][0]);
			}

			if (v2[1] + v2[n] <= w && v1[1] + v1[n] <= w)
			{
				clear();
				dp[1][0] = INF;
				dp[1][1] = INF;
				dp[1][2] = 2;
				func();
				ans = min(ans, dp[n - 1][2]);
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
