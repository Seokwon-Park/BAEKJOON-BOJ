#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

vector<int> adj[100005];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{ 
		int t, k;
		cin >> t >> k;
		if (t == 1)
		{
			cout << (adj[k].size() == 1 ? "no" : "yes");
		}
		else
		{
			cout << "yes";
		}
		cout << '\n';
	}


	return 0;
}