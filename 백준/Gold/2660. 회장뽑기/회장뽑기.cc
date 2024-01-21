#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

int d[55][55];
int answer = INT_MAX;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	for (int k = 1; k <= n; k++)
	{
		fill(d[k], d[k] + 405, INF);
		d[k][k] = 0;
	}


	while(true)
	{
		int u, v;
		cin >> u >> v;
		if (u == -1 && v == -1) break;
		d[u][v] = 1;
		d[v][u] = 1;
	}

	for (int k = 1; k <= n; k++)
		for (int s = 1; s <= n; s++)
			for (int t = 1; t <= n; t++)
				d[s][t] = min(d[s][t], d[s][k] + d[k][t]);

	vector<int> cand(n+1);
	for (int s = 1; s <= n; s++)
	{
		cand[s] = *max_element(d[s] + 1, d[s] + n + 1);
	}

	int mn = *min_element(cand.begin()+1, cand.end());
	int cnt = count(cand.begin(), cand.end(),mn);
	cout << mn << ' ' << cnt << '\n';
	for (int i = 1; i <= n; i++)
	{
		if (cand[i] == mn)
		{
			cout << i << ' ';
		}
	}

	return 0;
}