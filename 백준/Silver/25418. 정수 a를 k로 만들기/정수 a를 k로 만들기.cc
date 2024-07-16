#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int dp[1000005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	fill(dp, dp + 1000005, INF);
	int a, k;
	cin >> a >> k;
	dp[a] = 0;
	for (int i = a; i <= k; i++)
	{
		if (i % 2 == 0)
		{
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		dp[i] = min(dp[i], dp[i-1] + 1);
	}
	cout << dp[k];

	return 0;
}
