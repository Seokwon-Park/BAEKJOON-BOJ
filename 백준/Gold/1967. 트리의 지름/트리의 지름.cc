#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

vector<pii> adj[10005]; // cost, v;
bool v[10005];
int ans;

int mxdist = 0;
int mxnode = 0;

void dfs(int node, int dist)
{
	v[node] = true;
	bool isLeaf = true;
	for (auto [cost, nxt] : adj[node])
	{
		if (v[nxt])continue;
		isLeaf = false;
		dfs(nxt, dist + cost);
	}
	if (isLeaf)
	{
		if (mxdist < dist)
		{
			mxdist = dist;
			mxnode = node;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i = 0; i<n -1;i++)
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		adj[u].push_back({ cost, v });
		adj[v].push_back({ cost, u });
	}

	dfs(1, 0);
	fill(v, v + 10005, false);
	mxdist = 0;
	dfs(mxnode, 0);
	cout << mxdist;

	return 0;
}