#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int d[405][405];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	fill_n(&d[0][0], sizeof(d) / sizeof(int), INF);

	for (int i = 1; i <= n; i++)
	{
		d[i][i] = 0;
	}

	for (int i = 1; i <= k; i++)
	{
		int u, v;
		cin >> u >> v;
		d[u][v] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int s = 1; s <= n; s++)
		{
			for (int e = 1; e <= n; e++)
			{
				if (d[s][e] > d[s][i] + d[i][e])
					d[s][e] = d[s][i] + d[i][e];
			}
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		if (d[u][v] == INF && d[v][u] == INF)
			cout << 0;
		else if (d[u][v] == INF)
			cout << 1;
		else
			cout << -1;
		cout << '\n';
	}


	return 0;
}
