#include <bits/stdc++.h>

using namespace std;

bool bfs(int n, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& color)
{
	queue<int> q;
	q.push(n);
	visited[n] = true;
	color[n] = 1;

	while (!q.empty())
	{
		int num = q.front();
		q.pop();
		for (int nxt : adj[num])
		{
			if (color[nxt] == color[num]) return false;
			if (visited[nxt]) continue;
			color[nxt] = !color[num];
			visited[nxt] = true;
			q.push(nxt);
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int v, e;
		cin >> v >> e;
		vector<vector<int>> adj(v + 5);
		vector<bool> visited(v + 5);
		vector<int> color(v + 5, -1);
		
		for (int i = 0; i < e; i++)
		{
			int u, v;
			cin >> u >> v;

			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		bool chk = true;
		for (int i = 1; i <= v; i++)
		{
			if(!visited[i])
				if (!bfs(i, adj, visited, color))
				{
					chk = false;
					break;
				}
		}
		if (chk)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}


	return 0;
}