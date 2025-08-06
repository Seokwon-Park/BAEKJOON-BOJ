#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int dp[200000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 200000; i++)
	{
		dp[i] = (dp[i-1] + dp[i-2])%MOD;
	}
	while (t--)
	{
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}

	return 0;
}