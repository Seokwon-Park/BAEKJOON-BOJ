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

int dp[10000005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i < 10000005; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 10;
	}

	for (int i = n; i <= m; i++)
	{
		cout << dp[i];
	}


	return 0;
}