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

int v[100005];
int pf[100005];
int dp[100005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		pf[i] = pf[i - 1] + v[i];
	}

	int ans = 0;
	dp[m] = pf[m];
	for (int i = m + 1; i <= n; i++)
	{
		dp[i] = max(dp[i - 1] + v[i], pf[i] - pf[i - m]);
		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;
}