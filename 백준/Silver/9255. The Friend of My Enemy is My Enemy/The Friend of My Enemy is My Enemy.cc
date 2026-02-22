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



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for(int i = 1; i<= t; i++)
	{
		int n, m;
		cin >> n >> m;
		vector<vector<int>> adj(n+1, vector<int>());
		for (int j = 0; j < m; j++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int s;
		cin >> s;
		sort(adj[s].begin(), adj[s].end());
		adj[s].erase(unique(adj[s].begin(), adj[s].end()), adj[s].end());
		cout << "Data Set " << i << ":\n";
		for (auto j : adj[s])
		{
			cout << j << ' ';
		}
		cout << "\n\n";
	}

	return 0;
}