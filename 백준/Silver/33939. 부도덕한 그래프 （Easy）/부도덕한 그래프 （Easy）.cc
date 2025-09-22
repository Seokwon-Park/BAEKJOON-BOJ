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

bool connect[2005][2005];

vector<int> adj[2005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		connect[v][u] = true;
		connect[u][v] = true;
		adj[v].push_back(u);
	}

	ll ans = 0;
	for (int z = 1; z <= n; z++)
	{
		for (int i = 0; i< adj[z].size(); i++)
		{
			for (int j = i+1; j< adj[z].size(); j++)
			{
				int x = adj[z][i];
				int y = adj[z][j];
				if (connect[x][y] == false)
					ans++;
			}
		}
	}
	cout << ans;


	return 0;
}