#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1005];
bool visited[1005];


void bfs(int node)
{
	queue<int> q;
	q.push(node);
	visited[node] = true;
	while (!q.empty())
	{
		int n = q.front();
		q.pop();
		for (auto nxt: adj[n] )
		{
			if (visited[nxt]) continue;
			q.push(nxt);
			visited[nxt] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int answer = 0;
	

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			bfs(i);
			answer++;
		}
	}

	cout << answer;

	return 0;
}
