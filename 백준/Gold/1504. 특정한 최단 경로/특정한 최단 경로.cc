#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

vector<pair<int, int>> adj[805]; // adj[u] = {v,cost};
int d[805][805]; // 내위치가 i일 때, j로 가는 최단 경로.

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, e;
	cin >> n >> e;

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}

	int v1, v2;
	cin >> v1 >> v2;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 거리 최소 힙
	for (int i = 1; i <= n; i++)
	{
		fill(d[i], d[i] + n + 1, INF); // 일단 i에 위치했을 때의 테이블을 구한다.
		d[i][i] = 0; //i에서 i로 가는 거리는 0이다.
		pq.push({ d[i][i], i });
		while (!pq.empty())
		{
			int cost = pq.top().first;
			int cur = pq.top().second;
			pq.pop();
			if (d[i][cur] != cost) continue;
			for (auto [nxt, nxtc] : adj[cur])
			{
				if (d[i][nxt] > d[i][cur] + nxtc)
				{
					d[i][nxt] = d[i][cur] + nxtc;
					pq.push({ d[i][nxt], nxt });
				}
			}
		}
	}
	if (d[1][v1] == INF || d[v1][v2] == INF || d[v2][v1] == INF || d[v2][n] == INF)
	{
		cout << -1;
	}
	else
	{
		int answer = min(d[1][v1] + d[v1][v2] + d[v2][n], d[1][v2] + d[v2][v1] + d[v1][n]);
		cout << answer;
	}

	return 0;
}