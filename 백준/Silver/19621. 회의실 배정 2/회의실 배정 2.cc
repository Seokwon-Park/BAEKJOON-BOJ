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

pii v[30];
int h[30];
int dp[30];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i].first >> v[i].second >> h[i];
	}

	dp[1] = h[1];
	dp[2] = max(h[1], h[2]);

	for (int i = 3; i <= n; i++)
	{
		dp[i] = max(dp[i - 1], dp[i - 2] + h[i]);
	}

	cout << dp[n] << '\n';

	return 0;
}
