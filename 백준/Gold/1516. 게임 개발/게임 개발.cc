#include <bits/stdc++.h>

using namespace std;

vector<int> adj[505];
int deg[505];
int dp[505];
int build[505];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int t;
		cin >> t;
		build[i] = t;
		while (true)
		{
			int f;
			cin >> f;
			if (f == -1) break;
			adj[f].push_back(i);
			deg[i]++;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 0)
		{
			q.push(i);
			dp[i] = build[i];
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int nxt : adj[cur])
		{
			deg[nxt]--;
			dp[nxt] = max(dp[nxt], build[nxt] + dp[cur]);
			if (deg[nxt] == 0)
			{
				q.push(nxt);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << dp[i] << '\n';
	}

	return 0;
}