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

vector<int> adj[2005];
bool dst[2005];
bool comp[2005];
 
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
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int k;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int x;
		cin >> x;
		dst[x] = true;
	}

	vector<int> ans;
	for (int i = 1; i <= n; i++)
	{
		int cur = i;
		if (!dst[cur]) continue;
		bool isbomb = true;
		for (int nxt : adj[cur])
		{
			if (!dst[nxt])
			{
				isbomb = false;
				break;
			}
		}
		if (isbomb)
		{
			ans.push_back(i);
		}
	}
	for (auto i : ans)
	{
		comp[i] = true;
		for (int nxt : adj[i])
			comp[nxt] = true;
	}
	 
	if (ans.empty() || (count(comp+1, comp + n+1, 1) != count(dst+1,dst+n+1, 1))) cout << -1;
	else
	{
		cout << ans.size() << '\n';



		for (auto i : ans) cout << i << ' ';
	}


	return 0;
}