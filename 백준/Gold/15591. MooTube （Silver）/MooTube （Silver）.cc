#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

vector<pii> adj[5005];
int usado[5005];
bool v[5005];

int bfs(int start, int k)
{
	fill(v, v + 5005, false);
	queue<pii>q;
	v[start] = true;
	q.push({ 0,start });
	int ret = 0;
	while (!q.empty())
	{
		auto [cc, cur] = q.front();
		q.pop();
		for (auto [nxtc, nxt] : adj[cur])
		{
			int res = cc;
			if (v[nxt])continue;
			if (res == 0)
			{
				res = nxtc;
			}
			else
			{
				res = min(nxtc, res);
			}
			if (res >= k) ret++;
			v[nxt] = true;
			q.push({ res, nxt });
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n-1; i++)
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		adj[u].push_back({ cost,v });
		adj[v].push_back({ cost,u });
	}

	for (int i = 0; i < q; i++)
	{
		int k, v;
		cin >> k >> v;
		cout << bfs(v, k) << '\n';
	}



	return 0;
}
