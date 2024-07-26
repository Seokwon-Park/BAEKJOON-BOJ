#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

vector<int> adj[256];
int flow[256][256];
int capa[256][256];
bool v[256];
int parent[256];




bool bfs(int st, int en)
{
	fill(v, v + 256, false);
	queue<int> q;

	v[st] = true;
	q.push(st);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int nxt : adj[cur])
		{
			if (v[nxt] || capa[cur][nxt] - flow[cur][nxt] <= 0) continue;
			v[nxt] = true;
			q.push(nxt);
			parent[nxt] = cur;
		}
	}

	return v[en];
}

int max_flow(int st, int en)
{
	int value = 0;
	while (bfs(st, en))
	{
		int res = INF;
		for (int cur = en; cur != st; cur = parent[cur])
		{
			res = min(res, capa[parent[cur]][cur] - flow[parent[cur]][cur]);
		}

		for (int cur = en; cur != st; cur = parent[cur])
		{
			flow[parent[cur]][cur] += res;
		}

		value += res;
	}
	return value;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char u, v;
		int cap;
		cin >> u >> v >> cap;
		adj[u].push_back(v);
		adj[v].push_back(u);
		capa[u][v] += cap;
		capa[v][u] += cap;
	}

	cout << max_flow('A', 'Z');


	return 0;
}