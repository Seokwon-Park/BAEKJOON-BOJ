#include <bits/stdc++.h>

using namespace std;

int s, t;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> adj(n + 5);
	vector<int> dist(n + 5, 0);
	vector<bool> visited(n + 5, false);

	cin >> s >> t;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	queue<int> q;
	q.push(s);
	visited[s] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur == t) break;
		for (int nxt : adj[cur])
		{
			if (visited[nxt]) continue;
			q.push(nxt);
			dist[nxt] = dist[cur] + 1;
			visited[nxt] = true;
		}
	}

	if (dist[t] == 0)
		cout << -1;
	else

		cout << dist[t];

	return 0;
}