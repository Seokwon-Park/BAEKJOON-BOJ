#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> color(n + 1, -1);
		vector<vector<int>> adj(n + 1);

		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		int curColor = 1;
		bool isBipartite = true;
		for (int i = 1; i <= n; i++)
		{
			if (color[i] != -1) continue;
			queue<int> q;
			q.push(i);
			color[i] = curColor;
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();
				for (int nxt : adj[cur])
				{
					if (color[nxt] == -1)
					{
						color[nxt] = (color[cur] == 0?1 : 0);
						q.push(nxt);
					}
					else
					{
						if (color[nxt] == color[cur])
						{
							isBipartite = false;
							break;
						}
					}
				}
				if (!isBipartite)
				{
					break;
				}
			}
			if (!isBipartite)
			{
				break;
			}
		}
		if (!isBipartite)
		{
			cout << "impossible";
		}
		else
			cout << "possible";
		cout << '\n';

	}



	return 0;
}
