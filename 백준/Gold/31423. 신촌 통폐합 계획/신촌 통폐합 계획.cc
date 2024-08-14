#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

vector<int> adj[500005];
string m[500005];

void dfs(int node)
{
	cout << m[node];
	for (int nxt : adj[node])
		dfs(nxt);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		m[i] = s;
	}

	vector<bool> canbeRoot(n + 1, true);
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		canbeRoot[v] = false;
	}

	for (int i = 1; i <= n; i++)
	{
		if (canbeRoot[i])
			dfs(i);
	}
	

	return 0;
}