#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

vector<int> adj[1005];
bool v[1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> a >> b;

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (a == b)
	{
		cout << 0;
		return 0;
	}
	queue<int> q;
	q.push(a);
	v[a] = true;

	int dist = 0;
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			int cur = q.front();
			q.pop();
			for (int nxt : adj[cur])
			{
				if (v[nxt]) continue;
				if (nxt == b)
				{
					cout << dist + 1;
					return 0;
				}
				q.push(nxt);
				v[nxt] = true;
			}
		}
		dist++;
	}
	cout << -1;

	return 0;
}