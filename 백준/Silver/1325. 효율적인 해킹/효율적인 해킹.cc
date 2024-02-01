#include <bits/stdc++.h>

using namespace std;

vector<int> adj[10005];
int hack[10005];
int visited[10005];

int mx = INT_MIN;

void resetv()
{
	fill(visited, visited + 10005, false);
}

void bfs(int node)
{
	resetv();
	int hacking = 1;
	queue<int> q;
	q.push(node);
	visited[node] = true;
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int nxt : adj[cur])
		{
			if (visited[nxt]) continue;
			visited[nxt] = true;
			q.push(nxt);
			hack[node]++;
		}
	}
	mx = max(mx, hack[node]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		bfs(i);
	}

	for (int i = 1; i <= n; i++)
	{
		if (hack[i] == mx)
		{
			cout << i << ' ';
		}
	}

	return 0;
}
