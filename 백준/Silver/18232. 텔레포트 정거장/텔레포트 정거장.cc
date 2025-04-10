#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int n, m;
int s, e;
vector<int> adj[300005];
bool v[300005];

int bfs()
{
	queue<int> q;
	q.push(s);
	v[s] = true;
	int dist = 0;
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			int cur = q.front();
			q.pop();
			for (int nxt : adj[cur])
			{
				if (v[nxt]) continue;
				if (nxt == e)
				{
					return dist+1;
				}
				q.push(nxt);
				v[nxt] = true;
			}
		}
		dist++;
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	cin >> s >> e;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for (int x = 1; x <= n; x++)
	{
		if (x - 1 > 0)
		{
			adj[x].push_back(x - 1);
		}
		if (x + 1 <= n)
		{
			adj[x].push_back(x + 1);
		}
	}

	cout << bfs();
	
	return 0;
}