#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

vector<int> adj[100005];
bool v[100005];
int lv[100005];

void bfs(int root)
{
	queue<int> q;
	q.push(root);
	v[root] = true;
	int depth = 0;
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			int cur = q.front();
			q.pop();
			lv[cur] = depth;
			for (int nxt : adj[cur])
			{
				if (v[nxt]) continue;
				q.push(nxt);
				v[nxt] = true;
			}
		}
		depth++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, r;
	cin >> n >> m >> r;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	fill(lv, lv + n + 1, -1);
	bfs(r);
	for (int i = 1; i <= n; i++)
	{
		cout << lv[i] << '\n';
	}


	return 0;
}

