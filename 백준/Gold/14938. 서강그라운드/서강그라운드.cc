#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int d[105][105];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, r;
	cin >> n >> m >> r;

	for (int i = 0; i <= n; i++)
	{
		fill(d[i], d[i] + n + 5, INF);
		d[i][i] = 0;
	}

	vector<int> item(n+1);
	for (int i = 1; i <= n; i++)
	{
		cin >> item[i];
	}

	for (int i = 0; i < r; i++)
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		d[u][v] = cost;
		d[v][u] = cost;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int s = 1; s <= n; s++)
		{
			for (int t = 1; t <= n; t++)
			{
				d[s][t] = min(d[s][t], d[s][k] + d[k][t]);
			}
		}
	}

	int mx = INT_MIN;
	for (int i = 1; i <= n; i++)
	{
		int val = 0;
		for (int j = 1; j <= n; j++)
		{
			if (d[i][j] <= m)
			{
				val += item[j];
			}
		}
		mx = max(val, mx);
	}

	cout << mx;

	return 0;
}