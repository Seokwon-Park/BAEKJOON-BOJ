#include <bits/stdc++.h>

#define INF LLONG_MAX

using namespace std;

vector<pair<int, int>> adj[100005]; // v, cost;
bool v[1005];
int d[1005];

void bfs(int node, int target)
{
	queue<int> q;
	q.push(node);
	v[node] = true;
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		if (cur == target) break;
		for (auto [nxt, cost] : adj[cur])
		{
			if (v[nxt]) continue;
			d[nxt] = d[cur] + cost;
			v[nxt] = true;
			q.push(nxt);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;


	for (int i = 0; i < n - 1; i++)
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		adj[v].push_back({ u, cost });
		adj[u].push_back({ v, cost });
	}


	while (m--)
	{
		fill(d, d + 1005, 0);
		fill(v, v + 1005, false);
		int u, v;
		cin >> u >> v;

		bfs(u, v);

		cout << d[v] << '\n';
	}


	return 0;
}


