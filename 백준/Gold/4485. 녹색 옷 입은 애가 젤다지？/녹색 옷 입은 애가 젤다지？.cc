#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
using namespace std;

int board[130][130];
int d[130][130];


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ix = 1;
	while (true)
	{
		int n;
		cin >> n;
		if (n == 0) return 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> board[i][j];
				d[i][j] = INF;
			}
		}

		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
		pq.push({ board[0][0], 0,0 });
		d[0][0] = board[0][0];
		while (!pq.empty())
		{
			int x, y, cost;
			tie(cost, x, y) = pq.top(); pq.pop();
			if (d[y][x] != cost) continue;
			for (auto [nx, ny] : { make_pair(x-1, y) ,make_pair(x, y-1) ,make_pair(x+1, y) ,make_pair(x, y+1) })
			{
				if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
				if (d[ny][nx] > d[y][x] + board[ny][nx])
				{
					d[ny][nx] = d[y][x] + board[ny][nx];
					pq.push(tie(d[ny][nx], nx, ny));
				}
			}
		}

		cout << "Problem " << ix++ << ": " << d[n - 1][n - 1] << '\n';
	}

	return 0;
}
