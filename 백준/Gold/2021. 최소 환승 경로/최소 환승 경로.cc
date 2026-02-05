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

int n, l;
vector<int> adj[200005];
bool v[200005];

int bfs(int st, int en)
{
	queue<int> q;
	for (int nxt : adj[st])
	{
		q.push(nxt);
		v[nxt] = 1;
	}
	int d = 0;
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			int cur = q.front();
			q.pop();
			for (int nxt : adj[cur])
			{
				if (v[nxt])
					continue;
				if (nxt == en)
					return d/2;
				q.push(nxt);
				v[nxt] = 1;
			}
		}
		d++;
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> l;
	for (int i = 1; i <= l; i++)
	{
		int x;
		while (true)
		{
			cin >> x;
			if (x == -1) break;
			adj[n + i].push_back(x);
			adj[x].push_back(n + i);
		}
	}

	int st, en;
	cin >> st >> en;


	cout << bfs(st, en);

	return 0;
}