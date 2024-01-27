#include <bits/stdc++.h>

#define INF LLONG_MAX

using namespace std;

vector<pair<int, int>> adj[100005]; // v, cost;
long long d[100005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;


	for (int i = 0; i < m; i++)
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		adj[v].push_back({ u, cost });
	}

	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

	fill(d, d + n + 1, INF);

	for (int i = 0; i < k; i++)
	{
		int target;
		cin >> target;
		d[target] = 0;
		pq.push({ d[target], target });
	}

	while (!pq.empty())
	{
		auto [cost, cur] = pq.top();
		pq.pop();
		if (d[cur] != cost) continue;
		for (auto [nxt, nxtc] : adj[cur])
		{
			if (d[nxt] > d[cur] + nxtc)
			{
				d[nxt] = d[cur] + nxtc;
				pq.push({ d[nxt], nxt });
			}
		}
	}

	long long mx = *max_element(d + 1, d + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == mx)
		{
			cout << i << '\n';
			break;
		}
	}

	cout << mx;
	

	return 0;
}

