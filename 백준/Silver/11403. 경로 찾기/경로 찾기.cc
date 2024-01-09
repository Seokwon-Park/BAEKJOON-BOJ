#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int d[105][105];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n*n; i++)
	{
		cin >> d[i / n][i % n];
		if (d[i / n][i % n] == 0)
			d[i / n][i % n] = INF;
	}

	for (int k = 0; k < n; k++)
	{
		for (int s = 0; s < n; s++)
		{
			for (int t = 0; t < n; t++)
			{
				d[s][t] = min(d[s][t], d[s][k] + d[k][t]);
			}
		}
	}
	
	for (int s = 0; s < n; s++)
	{
		for (int t = 0; t < n; t++)
		{
			cout << (d[s][t] == INF ? 0 : 1) << ' ';
		}
		cout << '\n';
	}


	return 0;
}