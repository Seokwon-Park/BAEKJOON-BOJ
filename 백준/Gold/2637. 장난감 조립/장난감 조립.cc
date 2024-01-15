#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> adj[105];
int deg[105];
int dp[105][105]; // time to reach

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, k;
		cin >> x >> y >> k;
		adj[y].push_back({ x,k });
		deg[x]++;
	}

	vector<int> base_part;
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 0)
		{
			dp[i][i] = 1;
			base_part.push_back(i);
		}
	}
	
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 0)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto [nxt, mul] : adj[cur])
		{
			deg[nxt]--;
			for (int i = 1; i <= n; i++)
			{
				dp[nxt][i] += dp[cur][i] * mul;
			}
			if (deg[nxt] == 0)
			{
				q.push(nxt);
			}
		}
	}

	for (int part:base_part)
	{
		cout << part << ' ' << dp[n][part] << '\n';
	}

	return 0;
}