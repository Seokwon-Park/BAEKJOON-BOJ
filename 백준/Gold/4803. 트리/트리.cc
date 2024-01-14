#include <bits/stdc++.h>

using namespace std;

vector<int> adj[505];
bool visited[505];
int vcnt;
int ecnt;

void dfs(int node)
{
	if (visited[node]) return;
	vcnt++;
	visited[node] = true;
	for (int nxt : adj[node])
	{
		dfs(nxt);
		ecnt++;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc = 1;
	while (true)
	{
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		int answer = 0;

		fill(visited, visited + 505, false);
		fill(adj, adj + 505, vector<int>());
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		for (int i = 1; i <= n; i++)
		{
			vcnt = 0;
			ecnt = 0;
			if (!visited[i])
			{
				dfs(i);
				if (vcnt - 1 == ecnt / 2)answer++;
			}
		}
		if (answer <= 1)
		{
			cout << "Case " << tc++ << ": " << (answer ? "There is one tree." : "No trees.") << '\n';
		}
		else
		{
			cout << "Case " << tc++ << ": A forest of " << answer << " trees." << '\n';
		}
	}
	return 0;
}

