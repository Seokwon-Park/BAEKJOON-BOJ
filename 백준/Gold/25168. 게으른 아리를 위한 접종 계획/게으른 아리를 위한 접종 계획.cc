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
using hashmap = unordered_map<key, value>;

vector<pii> adj[10005];
int deg[10005];
int wait[10005];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;
		adj[s].push_back({ e, w });
		deg[e]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 0)
		{
			q.push(i);
		}
	}
	
	int ans = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto [nxt, cost] :adj[cur])
		{
			deg[nxt]--;
			if (cost < 7)
			{
				wait[nxt] = max(wait[nxt], wait[cur] + cost);
			}
			else
			{
				wait[nxt] = max(wait[nxt], wait[cur] + cost + 1);
			}

			if (deg[nxt] == 0)
			{
				q.push(nxt);
			}
		}
	}

	cout << *max_element(wait+1, wait+n+1) + 1;


	return 0;
}
