#include <bits/stdc++.h>

using namespace std;

vector<int> adj[505];
int visited[505];
int dst[505];

void bfs(int node)
{
	queue<int> q;
	q.push(node);
	visited[node] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int nxt : adj[cur])
		{
			if (visited[nxt]) continue;
			visited[nxt] = true;
			dst[nxt] = dst[cur] + 1;
			q.push(nxt);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
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

	bfs(1);

	int cnt = 0;
	for (int i = 2; i <= n; i++)
	{
		if (dst[i] == 0) continue;
		if (dst[i] <= 2)
		{
			cnt++;
		}
	}

	cout << cnt;


	return 0;
}