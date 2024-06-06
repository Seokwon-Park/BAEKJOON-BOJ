#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

vector<pii> adj[100005];
bool v[100005];
int maxvertex;
int maxlen;

void dfs(int node, int len)
{
	if (len > maxlen)
	{
		maxvertex = node;
		maxlen = len;
	}
	v[node] = true;
	for(auto [c,nxt] : adj[node])
	{
		if (v[nxt]) continue;
		dfs(nxt, len + c);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int u;
		cin >> u;
		while (1)
		{
			int v;
			cin >> v;
			if (v == -1)break;
			int cost;
			cin >> cost;
			adj[u].push_back({ cost,v });
		}
	}

	dfs(1, 0);
	//cout << maxvertex;
	fill(v, v + 100005, false);
	dfs(maxvertex, 0);

	cout << maxlen;

	return 0;
}