#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

vector<pii> adj[200005];
int p[200005];
int n, root;

pii findGiga(int node, int dist)
{
	if (node == root && adj[node].size() > 1)
	{
		return { node, dist };
	}
	if (adj[node].size() > 2)
	{
		return { node, dist };
	}
	for (auto [cost, nxt] : adj[node])
	{
		if (nxt == p[node]) continue;
		p[nxt] = node;
		return findGiga(nxt, dist + cost);
	}
	return { node, dist };
}

int findBranch(int node)
{
	int len = 0;
	if (adj[node].empty())
		return 0;
	for (auto [cost, nxt] : adj[node])
	{
		if (nxt == p[node]) continue;
		p[nxt] = node;
		len = max(len, findBranch(nxt) + cost);
	}
	return len;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> root;
	for (int i = 0; i < n-1; i++)
	{
		int a, b, d;
		cin >> a >> b >> d;
		adj[a].push_back({d, b});
		adj[b].push_back({ d, a });
	}
	 
	auto [giga, len] = findGiga(root, 0);
	cout << len << ' ';

	cout << findBranch(giga);

	return 0;
}