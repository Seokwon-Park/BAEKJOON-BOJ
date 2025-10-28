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

vector<int> adj[1005];
bool v[1005];

vector<int> bfs(int start, int moved)
{
	queue<int> q;
	q.push(start);
	int d = 0;
	while (!q.empty())
	{
		if (d == moved) break;
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			int cur = q.front();
			q.pop();
			for (int nxt : adj[cur])
			{
				if (v[nxt]) continue;
				v[nxt] = true;
				q.push(nxt);
			}
		}
		fill(v, v + 1005, false);
		d++;
	}

	if (q.empty())
	{
		return { -1 };
	}
	else
	{
		vector<int> ret;
		while (!q.empty())
		{
			ret.push_back(q.front());
			q.pop();
		}
		sort(ret.begin(), ret.end());
		return ret;
	}
	return { -1 };
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, x, y;
	cin >> n >> m >> x >> y;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	auto ans = bfs(x, y);
	for (auto i : ans)
	{
		cout << i << ' ';
	}

	return 0;
}