#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

vector<pair<int, int>> adj[1005]; // cost, v
int d[1005];
int pre[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
	}

	fill(d, d + 1005, INF);
	int st, ed;
	cin >> st >> ed;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	d[st] = 0;
	pq.push({ 0,st });
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int v = pq.top().second;
		pq.pop();
		if (cost != d[v]) continue;
		for (auto [nxtcost, nxtv] : adj[v])
		{
			if (d[v] + nxtcost < d[nxtv])
			{
				d[nxtv] = d[v] + nxtcost;
				pre[nxtv] = v;
				pq.push({ d[nxtv], nxtv });
			}
		}
	}

	cout << d[ed] << '\n';
	vector<int> path;
	int cur = ed;
	while (cur != 0)
	{
		path.push_back(cur);
		cur = pre[cur];
	}
	cout << path.size() << '\n';
	reverse(path.begin(), path.end());
	for (auto p : path)
	{
		cout << p << ' ';
	}

	return 0;
}