#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
using namespace std;

int d[255][255];

int main()
{
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
		int u, v, b;
		cin >> u >> v >> b;
		if (!b) // b가 한방향 길인 경우
			d[v][u] = 1; // v에서 u로 가기 위해 길을 1개 놓아야 한다.
		else // 양방향인 경우
			d[v][u] = 0; // v에서 u로 바로 갈 수 있다.
		d[u][v] = 0; // 단방향 양방향 관계없이 u에서 v로 바로 갈 수 있다.
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}

	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int s, e;
		cin >> s >> e;
		cout << d[s][e];
		cout << '\n';
	}
	//cout << '\n';
	//for (int i = 1; i <= n; i++)
	//{
	//	for (int j = 1; j <= n; j++)
	//		cout << d[i][j] << ' ';
	//	cout << '\n';
	//}

	return 0;
}