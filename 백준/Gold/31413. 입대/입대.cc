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

int v[2005];
int dp[2005][2005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	int a, d;
	cin >> a >> d;

	for (int i = 0; i <= n + d - 1; i++)
	{
		fill(dp[i], dp[i] + n + 1, -1);
	}

	dp[0][0] = 0;
	for (int i = 1; i <= n + d - 1; i++)
	{
		dp[i][0] = dp[i - 1][0] + v[i];
	}

	for (int i = d; i <= n + d - 1; i++)
	{
		for (int j = 1; j <= i / d; j++) 
		{
			dp[i][j] = dp[i - d][j - 1] + a;
			if (i - 1 >= j * d)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j] + v[i]);
			}
		}
	}

	int ans = -1;
	for (int j = 0; j <= n; j++)
	{
		if (dp[n + d - 1][j] >= m)
		{
			ans = j;
			break;
		}
	}
	cout << ans;


	return 0;
}