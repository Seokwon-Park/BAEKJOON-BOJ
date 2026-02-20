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

bool l[4100];
bool r[4100];
int d, n, u, t;
int dfscnt;
int bfscnt;
int lastdepth;

void init(int node, int maxnode)
{
	if (node * 2 < maxnode)
	{
		l[node] = 1;
		init(node * 2, maxnode);
	}
	if (node * 2 + 1 < maxnode)
	{
		r[node] = 1;
		init(node * 2 + 1, maxnode);
	}
}

void dfs(int node, int depth)
{
	dfscnt++;
	if (dfscnt == bfscnt)
	{
		lastdepth = depth;
		return;
	}
	if (l[node])
	{
		l[node] = 1;
		dfs(node * 2, depth + 1);
	}
	if (r[node])
	{
		r[node] = 1;
		dfs(node * 2 + 1, depth + 1);
	}
}

int bfs(int node)
{
	queue<tiii> q;
	q.push({ node, u, 0 });
	int res = 0;
	while (!q.empty())
	{
		auto [cur, cost, total] = q.front();
		res = max(res, total);
		bfscnt++; // 탐색 노드수
		q.pop();
		if (l[cur] && r[cur]) cost += t;
		if (l[cur])
		{
			q.push({ cur * 2, cost, total + cost });
		}
		if (r[cur])
		{
			q.push({ cur * 2 + 1, cost, total + cost });
		}
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> d >> n >> u >> t;

	init(1, 1 << d);

	for (int i = 0; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		if (v == u * 2)
		{
			l[u] = 0;
		}
		else if (v == u * 2 + 1)
		{
			r[u] = 0;
		}
	}
	int twin = bfs(1);
	dfs(1, 0);
	int pony = ((bfscnt - 1) * 2 - lastdepth) * u;
	
	if (twin == pony)
	{
		cout << ":blob_twintail_thinking:";
	}
	else if (twin > pony)
	{
		cout << ":blob_twintail_sad:";
	}
	else
	{
		cout << ":blob_twintail_aww:";
	}


	return 0;
}