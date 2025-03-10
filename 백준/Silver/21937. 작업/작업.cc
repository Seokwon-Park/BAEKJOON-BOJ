#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

vector<int> adj[100005];
int v[100005];
int result[100005];

int bfs(int x)
{
	queue<int> q;
	q.push(x);
	int result = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int nxt : adj[cur])
		{
			if (!v[nxt])
			{
				v[nxt] = true;
				result++;
				q.push(nxt);
			}
		}
	}
	return result;
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
		adj[v].push_back(u);
	}



	int x;
	cin >> x;
	cout << bfs(x);


	return 0;
}



