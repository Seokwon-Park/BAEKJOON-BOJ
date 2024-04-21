#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

vector<pair<int,int>> adj[10005];
int d[10005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, dd;
	cin >> n >> dd;

	for (int i = 0; i <= dd; i++)
	{
		d[i] = 0x3f3f3f;
	}
	for (int i = 0; i < n; i++)
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		adj[u].push_back({ cost, v });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[0] = 0;
	pq.push({ d[0], 0 });
	while (!pq.empty())
	{
		auto [cost, cur] = pq.top();
		pq.pop();
		if (d[cur] != cost) continue;
		vector<pair<int,int>> nxtv;
		nxtv.push_back({ 1,cur + 1 });
		for (auto p : adj[cur])
		{
			nxtv.push_back(p);
		}
		for (auto [nc, nxt] : nxtv)
		{
				if (d[nxt] <= d[cur] + nc) continue;
				d[nxt] = d[cur] + nc;
				pq.push({ d[nxt], nxt });

		}
		
	}
	cout << d[dd];



	return 0;
}