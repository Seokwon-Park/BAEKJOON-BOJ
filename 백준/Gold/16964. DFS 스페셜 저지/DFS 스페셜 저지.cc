#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

vector<int> adj[100005];
int d[100005];
int ix = 0;
bool v[100005];


void dfs(int node)
{
	ix++;
	v[node] = true;
	set<int> s;
	for (int nxt : adj[node])
	{
		if (v[nxt])continue;
		s.insert(nxt);
	}

	while(!s.empty())
	{
		if (s.find(d[ix]) != s.end())
		{
			s.erase(d[ix]);
			dfs(d[ix]);
		}
		else
		{
			cout << '0';
			exit(0);
		}
		
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> d[i];
	}

	if (d[0] != 1)
		cout << 0;
	else
	{
		dfs(1);
		cout << 1;
	}

	return 0;
}