#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

bool v[100005];
vector<int> lv(100005, -1);
vector<int> adj[100005];

void dfs(int node, int level)
{
	v[node] = true;
	lv[node] = level;
	sort(adj[node].begin(), adj[node].end(), greater<int>());
	for (int nxt : adj[node])
	{
		if (v[nxt])continue;
		dfs(nxt, level + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, r;
	cin >> n >> m >> r;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(r, 0);

	for (int i = 1; i <= n; i++)
	{
		cout << lv[i] << '\n';
	}

	
	return 0;
}
