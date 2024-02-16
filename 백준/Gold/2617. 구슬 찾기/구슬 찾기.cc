#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> light[105], heavy[105];
bool visited[105];

bool bfs(int node, vector<int> adj[105])
{
	fill(visited, visited + 105, false);
	queue<int> q;

	q.push(node);
	visited[node] = true;

	int w = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int nxt : adj[cur])
		{
			if (visited[nxt])continue;
			q.push(nxt);
			visited[nxt] = true;
			w++;
		}
	}
	return w >= (n + 1) / 2;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		light[a].push_back(b);
		heavy[b].push_back(a);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (bfs(i, light) || bfs(i, heavy))
		{
			ans++;
		}
	}

	cout << ans;


	return 0;
}