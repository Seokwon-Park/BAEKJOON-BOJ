#include <bits/stdc++.h>

#define INF 0x3f3f3f
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;

int d[505][505];

int out[505];
int in[505];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		fill(d[i] + 1, d[i] + n + 1, INF);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		d[u][v] = 1;

	}


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				d[j][k] = min(d[j][i] + d[i][k], d[j][k]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (d[i][j] < INF)
			{
				out[i]++;
			}
			if (d[j][i] < INF)
			{
				in[i]++;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (out[i] + in[i] == n - 1)
			ans++;
	}

	cout << ans;

	return 0;
}