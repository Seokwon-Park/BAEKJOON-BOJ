#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

vector<int> adj[123500];
bool v[123500];
ll amount[123500];
char type[123500];
ll p[123500];
ll wolf = 0;

ll dfs(int node)
{
	v[node] = true;
	bool isLeaf = true;
	ll res = 0;
	if (type[node] == 'S')
		res = amount[node];
	for (int nxt : adj[node])
	{
 		if (v[nxt]) continue;
		isLeaf = false;
		res += dfs(nxt);
	}
	if (isLeaf)
	{
		if (type[node] == 'S')
			return amount[node];
	}
	if (type[node] == 'W')
	{
		res = max(res - amount[node], 0LL);
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n; 
	for (int i = 2; i <= n; i++)
	{
		char t;
		ll a, p;
		cin >> t >> a >> p;
		adj[i].push_back(p);
		adj[p].push_back(i);
		amount[i] = a;
		type[i] = t;
	}

	cout << dfs(1);

	return 0;
}