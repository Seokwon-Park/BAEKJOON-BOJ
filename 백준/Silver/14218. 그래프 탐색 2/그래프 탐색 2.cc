#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

vector<int> adj[1005];
int d[1005];

void bfs(int x)
{
	queue<int> q;
	q.push(x);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int nxt : adj[cur])
		{
			if (d[cur] + 1 < d[nxt])
			{
				d[nxt] = d[cur] + 1;
				q.push(nxt);
			}
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	fill(d, d + n + 5, INF);
	d[1] = 0;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bfs(1);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		if (d[u] < d[v])
		{
			bfs(u);
		}
		else
		{
			bfs(v);
		}
		for (int j = 1; j <= n; j++)
		{
			cout << (d[j] == INF ? -1 : d[j]) << ' ';
		}
		cout << '\n';
	}


	return 0;
}