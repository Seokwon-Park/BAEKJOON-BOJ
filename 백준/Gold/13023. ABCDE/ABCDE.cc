#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

vi adj[2005];
bool visited[2005];

bool dfs(int node, int len)
{
	if (len >= 5)
		return true;
	visited[node] = true;
	for (int nxt : adj[node])
	{
		if (!visited[nxt])
			if (dfs(nxt, len + 1))
				return true;
			else
			{
				visited[nxt] = false;
				continue;
			}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		fill(visited, visited + 2005, false);
		if (dfs(i,1))
		{
			cout << 1;
			return 0;
		}
	}

	cout << 0;

	return 0;
}
