
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> adj[50005];
int d[50005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}

	fill(d, d + 50005, 0x3f3f3f3f);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[1] = 0;
	pq.push({ 0, 1 });
	while (!pq.empty())
	{
		auto [cost, cur] = pq.top();
		pq.pop();
		if (d[cur] != cost) continue;
		for (auto [nxtc, nxt] : adj[cur])
		{
			if (d[nxt] > d[cur] + nxtc)
			{
				d[nxt] = d[cur] + nxtc;
				pq.push({ d[nxt], nxt});
			}
		}
	}


	cout << d[n];

	return 0;
}