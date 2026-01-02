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

pii v[1005];
int dp[1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		v[i] = { x, y };

	}
	sort(v, v + m);
	fill(dp, dp + 1005, INF);
	dp[0] = 0;
	for (int i = 0; i < m; i++)
	{
		auto [x, y] = v[i];
		dp[y] = min(dp[y], x - 1);
		for (int j = i + 1; j < m; j++)
		{
			auto [a, b] = v[j];
			int gap = max(dp[y], a - y - 1);
			if (a <= y) continue;
			dp[b] = min(dp[b], gap);
		}
	}

	for (int i = 0; i < m; i++)
	{
		auto [x, y] = v[i];
		int gap = max(dp[y], n - y);
		dp[n] = min(dp[n], gap);
	}

	cout << dp[n];


	return 0;
}