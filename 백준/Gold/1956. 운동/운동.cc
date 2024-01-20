#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

int d[405][405];
int answer = INT_MAX;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	for (int k = 1; k <= n; k++)
	{
		fill(d[k], d[k] + 405, INF);
		d[k][k] = 0;
	}


	for (int i = 0; i < m; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		d[a][b] = cost;
	}

	for (int k = 1; k <= n; k++)
		for (int s = 1; s <= n; s++)
			for (int t = 1; t <= n; t++)
				d[s][t] = min(d[s][t], d[s][k] + d[k][t]);

	for (int s = 1; s <= n; s++)
		for (int t = 1; t <= n; t++)
		{
			if (s == t) continue;
			answer = min(answer, d[s][t] + d[t][s]);
		}
	if (answer >= INF)
	{
		cout << -1;
	}
	else
		cout << answer;


	return 0;
}
