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

ll dp[100005][15];
vector<pii> adj[100005];
vector<int> lift[100005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k, s, e;
	cin >> n >> m >> k >> s >> e;
	for (int i = 1; i <= n; i++)
	{
		fill(dp[i], dp[i] + k + 1, -1);
	}

	dp[s][0] = 0;

	for (int i = 0; i < m; i++)
	{
		int a, b, t;
		cin >> a >> b >> t;
		adj[a].push_back({ b, t });
		lift[b].push_back(a);
	}

	for (int i = 0; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dp[j][i] == -1)continue;
			for (auto [nxt, nxtc] : adj[j])
			{
				dp[nxt][i] = max(dp[nxt][i], dp[j][i] + nxtc);
			}
		}

		for (int j = 1; j <= n; j++)
		{
			if (dp[j][i] == -1) continue;
			for (int nxt : lift[j])
			{
				dp[nxt][i + 1] = max(dp[nxt][i + 1], dp[j][i]); 
			}
		}
	}

	cout << *max_element(dp[e], dp[e] + k + 1);

	return 0;
}