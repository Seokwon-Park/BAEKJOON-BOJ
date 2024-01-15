#include <bits/stdc++.h>

using namespace std;

vector<int> adj[10005];
int ttr[10005]; // time to reach
int worktime[10005];
int deg[10005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int t;
		cin >> t;
		worktime[i] = t;
		int d;
		cin >> d;
		deg[i] = d;
		for (int j = 0; j < d; j++)
		{
			int ad;
			cin >> ad;
			adj[ad].push_back(i);
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 0)
		{
			q.push(i);
			ttr[i] = worktime[i];
		}
	}
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int nxt : adj[cur])
		{
			deg[nxt]--;
			ttr[nxt] = max(ttr[cur] + worktime[nxt], ttr[nxt]);
			if (deg[nxt] == 0)
			{
				q.push(nxt);
			}
		}
	}
	cout << *max_element(ttr, ttr + n + 1);

	return 0;
}
