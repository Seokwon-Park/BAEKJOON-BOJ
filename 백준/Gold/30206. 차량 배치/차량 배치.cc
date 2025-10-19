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

vector<int> adj[200005];
bool v[200005];

vector<int> bfs()
{
	queue<int> q;
	q.push(1);
	v[1] = true;
	vector<int> res(1, 1);
	while (!q.empty())
	{
		int qs = q.size();
		int size = 0;
		for (int i = 0; i < qs; i++)
		{
			int cur = q.front();
			q.pop();
			for (int nxt : adj[cur])
			{
				if (v[nxt]) continue;
				size++;
				v[nxt] = true;
				q.push(nxt);
			}
		}
		res.push_back(size);
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> res = bfs();

	ll ans = 1;
	for (int i : res)
	{
		ans *= (i+1);
		ans %= MOD;
	}
	
	cout << ans - 1;

	return 0;
}