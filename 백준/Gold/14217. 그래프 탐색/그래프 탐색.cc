#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int n, m;
bool d[505][505];
bool v[505];
int dist[505];

void bfs()
{
	fill(v, v + n + 5, false);
	fill(dist, dist + n + 5, INF);
	queue<int> q;
	q.push(1);
	v[1] = 1;
	dist[1] = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (!d[cur][i] || v[i]) continue;
			dist[i] = dist[cur] + 1;
			q.push(i);
			v[i] = true;
		}
	}

	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		d[u][v] = 1;
		d[v][u] = 1;
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
		{
			d[b][c] = 1;
			d[c][b] = 1;
		}
		else
		{
			d[b][c] = 0;
			d[c][b] = 0;
		}

		bfs();
		for (int i = 1; i <= n; i++)
		{
			cout << (dist[i] == INF? -1 : dist[i]) << ' ';
		}
		cout << '\n';
	}

	return 0;
}
