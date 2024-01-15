#include <bits/stdc++.h>

using namespace std;

bool chk[1005];
double d[1005][1005];
map<int, pair<int, int>> gods;

double cal(int a, int b)
{
	double res;
	double x1 = gods[a].first;
	double y1 = gods[a].second;
	double x2 = gods[b].first;
	double y2 = gods[b].second;

	double xdiff = x1 - x2;
	double ydiff = y1 - y2;

	res = xdiff * xdiff + ydiff * ydiff;

	return sqrt(res);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;


	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		gods[i] = make_pair(x, y);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			d[i][j] = cal(i, j);
			d[j][i] = d[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		d[u][v] = 0;
		d[v][u] = 0;
	}

	priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, greater<tuple<double, int, int>>> pq;

	chk[1] = true;
	for (int j = 2; j <= n; j++)
	{
		if (chk[j]) continue;
		pq.push({ d[1][j], 1, j});
	}
	int cnt = 0;
	double answer = 0;
	while (cnt < n - 1)
	{
		double cost;
		int a, b;
		tie(cost, a, b) = pq.top();
		pq.pop();
		if (chk[b]) continue;
		answer += cost;
		chk[b] = true;
		cnt++;
		for (int j = 1; j <= n; j++)
		{
			if (b == j) continue;
			if (chk[j]) continue;
			pq.push({ d[b][j], b, j });
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << answer;


	return 0;
}