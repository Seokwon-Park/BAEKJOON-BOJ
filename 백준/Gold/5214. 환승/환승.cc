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

int n, k, m;
vector<int> adj[101005];
bool v[101005];

int bfs()
{
	queue<int> q;
	q.push(1);
	v[1] = true;
	int d = 1;
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			int cur = q.front();
			q.pop();
			if (cur == n) return d;
			for (int nxt : adj[cur])
			{
				if (v[nxt]) continue;
				v[nxt] = true;
				q.push(nxt);
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


	cin >> n >> k >> m;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < k; j++)
		{
			int x;
			cin >> x;
			adj[x].push_back(n + i);
			adj[n + i].push_back(x);
		}
	}

	int res = bfs();
	cout << (res == -1 ? res : (res + 1) / 2);

	return 0;
}