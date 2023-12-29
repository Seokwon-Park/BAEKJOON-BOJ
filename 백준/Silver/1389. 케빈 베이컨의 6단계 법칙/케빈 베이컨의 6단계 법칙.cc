#include <bits/stdc++.h>

using namespace std;

int graph[105][105];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		fill(graph[i]+1, graph[i] + n + 5, 0x3f3f3f3f);
		graph[i][i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u][v] = 1;
		graph[v][u] = 1;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int s = 1; s <= n; s++)
		{
			for (int t = 1; t <= n; t++)
			{
				graph[s][t] = min(graph[s][k] + graph[k][t], graph[s][t]);
			}
		}
	}

	int min_val = INT_MAX;
	int human = 0;

	for (int i = 1; i <= n; i++)
	{
		int bacon = 0;
		for (int j = 1; j <= n; j++)
		{
			bacon += graph[i][j];
		}
		if (min_val > bacon) // 어차피 1번 사람부터 측정하기 때문에 뒤에 나오는 사람이 더 작은게 아닌 이상 무조건 가장 번호ㄱ ㅏ작은 사람인게 보장된다.
		{
			min_val = bacon;
			human = i;
		}
	}

	cout << human;

	return 0;
}