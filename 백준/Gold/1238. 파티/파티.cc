#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

vector<pair<int, int>> adj[1005];
int d[1005][1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, x;
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++)
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		adj[u].push_back({ v, cost });
	}

	for (int i = 1; i <= n; i++)
	{
		fill(d[i], d[i] + 1005, INF);
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	//d[x][x] = 0;
	//pq.push({ 0, x });
	//while (!pq.empty())
	//{
	//	int cost = pq.top().first;
	//	int cur = pq.top().second;
	//	pq.pop();
	//	if (d[x][cur] != cost) continue;
	//	for (auto [nxt, c] : adj[cur])
	//	{
	//		if (d[x][cur] + c < d[x][nxt])
	//		{
	//			d[x][nxt] = d[x][cur] + c;
	//			pq.push({ d[x][nxt], nxt });
	//		}
	//	}
	//}

	for (int i = 1; i <= n; i++)
	{
		d[i][i] = 0;

		pq.push({ 0, i });
		while (!pq.empty())
		{
			int cost = pq.top().first;
			int cur = pq.top().second;
			pq.pop();
			if (d[i][cur] != cost) continue;
			for (auto [nxt, c] : adj[cur])
			{
				if (d[i][cur] + c < d[i][nxt])
				{
					d[i][nxt] = d[i][cur] + c;
					pq.push({ d[i][nxt], nxt });
				}
			}
		}
	}

	int mx = INT_MIN;
	for (int i = 1; i <= n; i++)
	{
		mx = max(d[i][x] + d[x][i], mx);
	}

	cout << mx; 
	/*
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << d[i][j] << ' ';
		}
		cout << '\n';
	}*/

	return 0;
}