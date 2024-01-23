#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

vector<int> adj[300005];
int d[300005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k, x;
	cin >> n >> m >> k >> x;

	fill(d, d + 300005, INF);

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({ 0, x });
	d[x] = 0;
	while (!pq.empty())
	{
		auto [cost, cur] = pq.top();
		pq.pop();
		for (int nxt : adj[cur])
		{
			if (d[nxt] > d[cur] + 1)
			{
				d[nxt] = d[cur] + 1;
				pq.push({ d[nxt], nxt });
			}
		}
	}

	vector<int> ans;
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == k)
			ans.push_back(i);
	}

	if (ans.empty())
		cout << -1;
	else
		for (int i : ans)
			cout << i << '\n';

	return 0;
}