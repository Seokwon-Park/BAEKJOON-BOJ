#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100005];
bool visited[100005];

int seq[100005];
int s = 1;

int n, m, r;

void bfs(int pos)
{
	seq[pos] = s;
	s++;

	for (int i = 0; i <= n; i++)
	{
		sort(adj[i].begin(), adj[i].end());
	}
	
	queue<int> q;
	q.push(pos);
	while (!q.empty())
	{
		int fr = q.front();
		q.pop();
		for (int i : adj[fr])
		{
			if (visited[i]) continue;
			q.push(i);
			visited[i] = true;
			seq[i] = s++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> n >> m >> r;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	visited[r] = true; 
	bfs(r);

	for (int i = 1; i <= n; i++)
	{
		cout << seq[i] << '\n';
	}
	
	return 0;
}
