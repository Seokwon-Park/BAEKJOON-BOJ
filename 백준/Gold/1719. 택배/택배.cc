#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int d[205][205];
int nxt[205][205];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
	{
		fill(d[i], d[i] + n + 1, INF);
		d[i][i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		d[u][v] = cost;
		d[v][u] = cost;
		nxt[u][v] = v;
		nxt[v][u] = u;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int s = 1; s <= n; s++)
		{
			for (int e = 1; e <= n; e++)
			{
				if (d[s][e] > d[s][k] + d[k][e])
				{
					d[s][e] = d[s][k] + d[k][e];
					nxt[s][e] = nxt[s][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) cout << "- ";
			else
				cout << nxt[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}