#include <bits/stdc++.h>

using namespace std;

int adj[105][105];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		fill(adj[i], adj[i] + 105, 0x3f3f3f3f);
		adj[i][i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a][b] = min(adj[a][b], c);
	}

	for (int k = 1; k <= n; k++)
	{
		for (int s = 1; s <= n; s++)
		{
			for (int t = 1; t <= n; t++)
			{
				adj[s][t] = min(adj[s][t], adj[s][k] + adj[k][t]);
			}
		}
	}

	for (int s = 1; s <= n; s++)
	{
		for (int t = 1; t <= n; t++)
		{
			if (adj[s][t] == 0x3f3f3f3f) cout << "0 ";
			else
			cout << adj[s][t] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
