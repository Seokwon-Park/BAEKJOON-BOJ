#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int d[105][105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		fill(d[i], d[i] + n + 1, INF);
		d[i][i] = 0;
	}

	for (int i = 0; i < m; i++)
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
				d[s][e] = min(d[s][e], d[s][i]+ d[i][e]);
			}
		}
	}

	vector<int> v(n + 1, 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			if (d[i][j] < INF)
				v[i]++;
			if (d[j][i] < INF)
				v[i]++;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << n - v[i] << '\n';
	}

	
	return 0;
}