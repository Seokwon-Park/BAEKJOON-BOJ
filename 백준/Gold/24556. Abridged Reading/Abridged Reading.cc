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

int v[1005];
int p[1005];
int dp[1005];
int leaf[1005];
vector<int> adj[1005];
int depth[1005];

void dfs(int x, int dep, int p)
{
	dp[x] += v[x] + dp[p];
	depth[x] = dep;
	for (int nxt : adj[x])
	{
		dfs(nxt, dep+1, x);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		leaf[i] = true;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		p[b] = a;
		leaf[a] = false;
		adj[a].push_back(b);
	}

	for (int i = 1; i <= n; i++)
	{
		if (p[i] == 0)
		{
			adj[0].push_back(i);
			p[i] = 0;
		}
	}

	dfs(0, 0, 0);

	int ans = INF;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (!leaf[i] || !leaf[j]) continue;
			
			int a = i;
			int b = j;
			while (depth[a] != depth[b])
			{
				if (depth[a] < depth[b])
				{
					b = p[b];
				}
				else
				{
					a = p[a];
				}
			}
			while (a != b)
			{
				a = p[a];
				b = p[b];
			}

			ans = min(ans ,dp[i] + dp[j] - dp[a]);
		}
	}
	cout << ans;

	return 0;
}
