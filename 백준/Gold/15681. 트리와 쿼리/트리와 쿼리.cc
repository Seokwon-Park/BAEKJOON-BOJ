#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100005];
vector<int> child[100005];
bool visited[100005];
int p[100005];
int sz[100005];

void dfs2(int node)
{
	sz[node] = 1;
	for (int nxt : child[node])
	{
		dfs2(nxt);
		sz[node] += sz[nxt];
	}
}

void dfs(int node)
{
	for (int nxt : adj[node])
	{
		if (nxt == p[node]) continue;
		p[nxt] = node;
		child[node].push_back(nxt);
		dfs(nxt);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, r, q;
	cin >> n >> r >> q;
	for (int i = 0; i < n-1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(r);
	dfs2(r);
	for (int i = 0; i < q; i++)
	{
		int query;
		cin >> query;
		cout << sz[query] << '\n';
	}

	return 0;
}