#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

vector<pair<int, int>> adj[1005];
int d[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		adj[a].push_back({ cost, b });
	}

	fill(d, d + 1005, INF);
	
	int st, ed;
	cin >> st >> ed;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

	d[st] = 0;
	pq.push({ 0, st });
	while (!pq.empty())
	{
		auto [cost, cur] = pq.top();
		pq.pop();
		if (d[cur] != cost) continue; // 현재위치까지의 최솟값과 든 비용이 같지 않으면 continue
		for (auto [nxtc, nxt] : adj[cur])
		{
			if (d[cur] + nxtc < d[nxt])
			{
				d[nxt] = d[cur] + nxtc;
				pq.push({ d[nxt], nxt });
			}
		}
	}

	cout << d[ed];

	return 0;
}