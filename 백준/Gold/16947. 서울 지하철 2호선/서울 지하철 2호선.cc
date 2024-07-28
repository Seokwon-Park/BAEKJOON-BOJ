#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

vector<int> adj[3005];
bool isCycle[3005];
bool v[3005];
int parent[3005];
bool isFind; // isFindCycle?

int checkDist(int node)
{
	fill(v, v + 3005, false);
	queue<int> q;
	q.push(node);
	v[node] = true;
	int dist = 1;
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
				if (isCycle[nxt]) return dist;
				q.push(nxt);
				v[nxt] = true;

			}
		}
		dist++;
	}
}
void findCycle(int cur)
{
	v[cur] = true;
	for (int nxt : adj[cur])
	{
		if (v[nxt])
		{
			if (nxt != parent[cur]) {
				isCycle[nxt] = true;
				for (int x = cur; x != nxt; x = parent[x])
				{
					isCycle[x] = true;
				}
				isFind = true;
				return;
			}
			continue;
		}
		else
		{
			parent[nxt] = cur;
			findCycle(nxt);
			if (isFind)return;
		}

	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	findCycle(1);

	for (int i = 1; i <= n; i++)
	{
		if (isCycle[i])
			cout << 0;
		else
			cout << checkDist(i);
		cout << ' ';
	}

	return 0;
}