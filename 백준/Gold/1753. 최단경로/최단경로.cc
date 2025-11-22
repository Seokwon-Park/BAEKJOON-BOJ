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

int v, e;
int k;
vector<pii> adj[20005];
int d[20005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> v >> e >> k;
	fill(d, d + v + 1, INF);
	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
	}

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	d[k] = 0;
	pq.push({ 0, k });
	while (!pq.empty())
	{
		auto [cost, cur] = pq.top(); pq.pop();
		if (d[cur] != cost) continue;
		for (auto [ncost, nxt] : adj[cur])
		{
			if (d[cur] + ncost >= d[nxt]) continue;
			d[nxt] = d[cur] + ncost;
			pq.push({ d[nxt], nxt });
		}
	}

	for (int i = 1; i <= v; i++)
	{
		cout << (d[i] == INF? "INF" : to_string(d[i])) << '\n';
	}

	return 0;
}