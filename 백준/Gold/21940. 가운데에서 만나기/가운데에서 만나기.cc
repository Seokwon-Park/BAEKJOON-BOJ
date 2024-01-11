#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

int d[205][205];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		fill(d[i]+1, d[i] + n + 1, INF);
		d[i][i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		d[u][v] = c;
	}

	int k;
	cin >> k;
	vector<int> friends;
	for (int i = 0; i < k; i++)
	{
		int n; cin >> n;
		friends.push_back(n);
	}

	for (int k = 1; k <= n; k++)
	{
		for (int s = 1; s <= n; s++)
		{
			for (int t = 1; t <= n; t++)
			{
				d[s][t] = min(d[s][t], d[s][k] + d[k][t]);
			}
		}
	}

	vector<pair<int,int>> list;
	for (int s = 1; s <= n; s++)
	{
		int mx = INT_MIN;
		for (int i : friends)
		{
			mx = max(mx, d[i][s] + d[s][i]);
		}
		list.push_back({ mx, s });
	}

	int mn = min_element(list.begin(), list.end())->first;
	sort(list.begin(), list.end());

	for (auto p : list)
	{
		if (p.first == mn)
			cout << p.second << ' ';
	} 

	return 0;
}