#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1005];
int deg[1005];
vector<int> sem(1005, 1);



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		deg[b]++;
	}

	queue<int> q;

	int now= 1;
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 0)
		{
			q.push(i);
		}
	}


	while (!q.empty())
	{
		now++;
		int qs = q.size();
		for (int i = 0; i < q.size(); i++)
		{
			int cur = q.front(); q.pop();
			for (int nxt : adj[cur])
			{
				deg[nxt]--;
				if (deg[nxt] == 0)
				{
					q.push(nxt);
					sem[nxt] = sem[cur]+1;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << sem[i] << ' ';
	}


	return 0;
}