#include <bits/stdc++.h>

using namespace std;

int p[500005];
int dist[500005];
int c[500005];
vector<int> adj[500005];
bool visited[500005];
int d;

void bfs(int node)
{
	queue<int> q;
	q.push(node);
	visited[node] = true;
	while (!q.empty())
	{
		int n = q.front();
		q.pop();
		for (auto nxt : adj[n])
		{
			if (visited[nxt]) continue;
			p[nxt] = n;
			dist[nxt] = dist[n] + 1;
			c[n]++;
			q.push(nxt);
			visited[nxt] = true;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
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

	bfs(1);
	
	for (int i = 1; i <= n; i++)
	{
		if (c[i] == 0)
			d += dist[i];
	}

	if (d % 2 == 0)
		cout << "No";
	else
		cout << "Yes";


	return 0;
}