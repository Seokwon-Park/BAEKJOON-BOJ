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

int dp[1000005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x;
	cin >> x;

	for (int i = 2; i <= x; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 6 == 0)
		{
			dp[i] = min({dp[i / 2], dp[i / 3], dp[i - 1]}) + 1;
		}
		else if (i % 3 == 0)
		{
			dp[i] = min(dp[i / 3], dp[i-1]) + 1;
		}
		else if ( i%2 == 0)
		{
			dp[i] = min(dp[i / 2], dp[i-1]) + 1;
		}

	}

	cout << dp[x];

	return 0;
}