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

bool v[1005][105];
int cnt[1005];

vector<int> adj[1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k, n, m;
	cin >> k >> n >> m;
	queue<pii> q;
	for (int i = 1; i <= k; i++)
	{
		int x;
		cin >> x;
		q.push({ x, i });
		cnt[x]++;
		v[x][i] = 1;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}

	while (!q.empty())
	{
		auto [loc, num] = q.front();
		q.pop();
		for (int nxt : adj[loc])
		{
			if (v[nxt][num]) continue;
			q.push({ nxt, num });
			cnt[nxt]++;
			v[nxt][num] = 1;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] == k)
		{
			ans++;
		}
	}
	cout << ans;

	return 0;
}