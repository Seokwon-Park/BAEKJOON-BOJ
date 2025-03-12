#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dp[50005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	dp[1] = 1;
	int n;
	cin >> n;
	for (ll i = 2; i <= n; i++)
	{
		dp[i] = INF;
		for (ll j = 1; j * j <= i; j++)
		{
			dp[i] = min(dp[i], 1 + dp[i - j * j]);
		}
	}
	cout << dp[n];
	

	return 0;
}