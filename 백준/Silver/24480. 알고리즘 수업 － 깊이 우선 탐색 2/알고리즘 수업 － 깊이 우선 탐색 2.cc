#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100005];
bool visited[100005];

int seq[100005];
int s = 1;

void dfs(int pos)
{
	seq[pos] = s;
	s++;
	sort(adj[pos].rbegin(), adj[pos].rend());
	for (auto i : adj[pos])
	{
		if (visited[i]) continue;
		visited[i] = true;
		dfs(i);
	}
}

int main() {
	ios::sync_with_stdio(0);
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

	visited[r] = true; 
	dfs(r);

	for (int i = 1; i <= n; i++)
	{
		cout << seq[i] << '\n';
	}
	
	return 0;
}
