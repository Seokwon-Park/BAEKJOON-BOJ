#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

vector<pii> adj[10005];
bool v[10005];
int st = -1;
int mx = 0;
int dist = 0;

void findst(int x)
{
	v[x] = 1;
	for (auto [nd, nxt] : adj[x])
	{
		if (v[nxt])
		{
			if (mx < dist)
			{
				mx = dist;
				st = x;
			}
			continue;
		}
		dist += nd;
		findst(nxt);
		dist -= nd;
	}
}

void dfs(int x)
{
	v[x] = 1;
	for (auto [nd, nxt] : adj[x])
	{
		if (v[nxt])
		{
			if (mx < dist)
			{
				mx = dist;
			}
			continue;
		}
		dist += nd;
		dfs(nxt);
		dist -= nd;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, d;
	while (cin >> a >> b >> d)
	{
		adj[a].push_back({ d, b });
		adj[b].push_back({ d, a });
	}

	findst(1);
	fill(v, v + 10005, 0);
	mx = 0;
	dist = 0;
	dfs(st);
	cout << mx;

	return 0;
}