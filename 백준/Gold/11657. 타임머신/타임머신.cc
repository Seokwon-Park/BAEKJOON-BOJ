#include <bits/stdc++.h>

using namespace std;

#define INF LLONG_MAX

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;

ll d[505];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	fill(d, d + 505, LLONG_MAX);
	vector<tiii> edges(m);
	for (int i = 0; i < m; i++)
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		edges[i] = tie(u, v, cost);
	}

	d[1] = 0;
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int u, v;
			ll cost;
			tie(u, v, cost) = edges[j];
			if (d[u] == LLONG_MAX)continue;
			if (d[u] + cost < d[v])
			{
				d[v] = d[u] + cost;
			}
		}
	}

	for (int j = 0; j < m; j++)
	{
		int u, v;
		ll cost;
		tie(u, v, cost) = edges[j];

		if (d[u] == LLONG_MAX)continue;
		if (d[u] + cost < d[v])
		{
			cout << -1;
			return 0;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (d[i] == LLONG_MAX)
			cout << -1;
		else
			cout << d[i];
		cout << '\n';
	}

	return 0;
}