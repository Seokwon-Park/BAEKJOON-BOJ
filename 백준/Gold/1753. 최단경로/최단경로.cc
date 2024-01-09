#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
using namespace std;

vector<pair<int, int>> adj[20005];
int d[20005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(d, d + 20005, INF);
	int v, e;
	cin >> v >> e;
	int st;
	cin >> st;
	d[st] = 0;
	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
	}

	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

	pq.push({ 0, st });

	while (!pq.empty())
	{
		auto p = pq.top();
		pq.pop();
		if (p.first != d[p.second])continue;
		for (auto nxt : adj[p.second])
		{
			if (d[p.second] + nxt.first < d[nxt.second])
			{
				d[nxt.second] = d[p.second] + nxt.first;
				pq.push({ d[nxt.second], nxt.second });
			}
		}
	}

	for (int i = 1; i <= v; i++)
	{
		if (d[i] == INF)
			cout << "INF\n";
		else
			cout << d[i] << '\n';
	}

	return 0;
}