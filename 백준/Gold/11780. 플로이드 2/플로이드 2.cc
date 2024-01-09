#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int graph[105][105];
int nxt[105][105];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		fill(graph[i], graph[i] + n + 1, INF);
		graph[i][i] = 0;
	}


	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u][v] = min(w, graph[u][v]);
		nxt[u][v] = v;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int s = 1; s <= n; s++)
		{
			for (int t = 1; t <= n; t++)
			{
				if (graph[s][t] > graph[s][k] + graph[k][t]) // 경유 하는 루트가 더 짧으면 갱신하고 pre 테이블에 등록
				{
					graph[s][t] = graph[s][k] + graph[k][t];
					nxt[s][t] = nxt[s][k];
				}
			}
		}
	}

	for (int s = 1; s <= n; s++)
	{
		for (int t = 1; t <= n; t++)
		{
			if (graph[s][t] == INF)
				cout << "0 ";
			else
				cout << graph[s][t] << ' ';
		}
		cout << '\n';
	}

	for (int s = 1; s <= n; s++)
	{
		for (int t = 1; t <= n; t++)
		{
			if (graph[s][t] == 0 || graph[s][t] == INF)
			{
				cout << "0\n";
				continue;
			}
			vector<int> path;
			int cur = s;
			while (cur != t)
			{
				path.push_back(cur);
				cur = nxt[cur][t];
			}
			path.push_back(cur);
			cout << path.size() << ' ';
			for (auto p : path)
			{
				cout << p << ' ';
			}
			cout << '\n';
		}
	}

	return 0;
}
