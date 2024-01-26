#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

vector<int> adj[20005];
int d[20005];
int answer = INT_MAX;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	fill(d, d + 20005, INF);
	for (int k = 0; k < m; k++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0,1});
	d[1] = 0;
	while (!pq.empty())
	{
		auto [cost, cur] = pq.top(); pq.pop();
		if (d[cur] != cost) continue;
		for (int nxt : adj[cur])
		{
			if (d[nxt] > d[cur] + 1)
			{
				d[nxt] = d[cur] + 1;
				pq.push({d[nxt], nxt});
			}
		}

	}

	int mx = *max_element(d + 1, d + n + 1);
	vector<int> maxd;
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == mx)
		{
			maxd.push_back(i);
		}
	}

	cout << maxd[0] << ' ' << d[maxd[0]] << ' ' << maxd.size();


	return 0;
}
