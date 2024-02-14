#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

vector<pair<int, int>> adj[1005]; // cost, b;
map<int, map<int, vector<int>>> adjj;


int n, m;
int d[1005];
int d2[1005];
int pre[1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	fill(d, d + 1005, INF);
	fill(d2, d2 + 1005, INF);

	vector<tuple<int, int, int>> road;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		//road.push_back(tie(a, b, c));
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
		adjj[a][b].push_back(c);
		adjj[b][a].push_back(c);
	}

	for (int a = 1; a <= n; a++)
		for (int b = 1; b <= n; b++)
			sort(adjj[a][b].begin(), adjj[a][b].end());

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	d[1] = 0;
	pq.push({ 0, 1 });
	while (!pq.empty())
	{
		auto [cost, cur] = pq.top();
		pq.pop();
		if (d[cur] < cost) continue;
		for (auto [nxtc, nxt] : adj[cur])
		{
			if (d[nxt] > d[cur] + nxtc)
			{
				d[nxt] = d[cur] + nxtc;
				pre[nxt] = cur;
				pq.push({ d[nxt],nxt });
			}
		}
	}

	int cur = n;
	map<int, map<int, bool>> block;
	while (cur != 1)
	{
		block[pre[cur]][cur] = true;
		block[cur][pre[cur]] = true;
		cur = pre[cur];
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;

	d2[1] = 0;
	pq2.push({ 0, 1 });
	while (!pq2.empty())
	{
		auto [cost, cur] = pq2.top();
		pq2.pop();
		if (d2[cur] < cost) continue;
		for (auto [nxtc, nxt] : adj[cur])
		{
			if (block[cur][nxt])
			{
				if (adjj[cur][nxt].size() > 1)
				{
					if (d2[nxt] > d2[cur] + adjj[cur][nxt][1])
					{
						d2[nxt] = d2[cur] + adjj[cur][nxt][1];
						pq2.push({ d2[nxt],nxt });
					}
				}
				continue;
			}
			if (d2[nxt] > d2[cur] + nxtc)
			{
				d2[nxt] = d2[cur] + nxtc;
				pq2.push({ d2[nxt],nxt });
			}
		}
	}

	cout << d2[n];

	return 0;
}