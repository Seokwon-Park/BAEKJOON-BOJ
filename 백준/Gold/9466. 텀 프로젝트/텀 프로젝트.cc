#include <bits/stdc++.h>

using namespace std;

int adj[100005];
bool visited[100005];
bool used[100005];
int answer = 0;
int n;

void dfs(int node)
{
	visited[node] = true;
	if (!visited[adj[node]])
	{
		dfs(adj[node]);
	}
	else
	{
		if (!used[adj[node]])
		{
			for (int i = adj[node]; i != node; i = adj[i])
			{
				answer++;
			}
			answer++;
		}
	}
	used[node] = true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--)
	{
		answer = 0;
		cin >> n;
		fill(used, used + n + 5, false);
		fill(visited, visited + n + 5, false);
		for (int i = 1; i <= n; i++)
		{
			int v;
			cin >> v;
			adj[i] = v;
		}

		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				dfs(i);
			}
		}

		cout << n - answer << '\n';
	}

	return 0;
}