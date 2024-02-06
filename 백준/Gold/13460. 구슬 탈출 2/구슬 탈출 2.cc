#include <bits/stdc++.h>

using namespace std;

int n, m;
char board[11][11];
int dist[11][11][11][11]; // moved
int rx, ry;
int bx, by;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int bfs()
{
	queue<tuple<int, int, int, int>> q;
	q.push({ rx, ry, bx, by });
	dist[rx][ry][bx][by] = 0;
	while (!q.empty())
	{
		tie(rx, ry, bx, by) = q.front();
		q.pop();

		int cnt = dist[rx][ry][bx][by];
		if (cnt >= 10) return -1;
		for (int i = 0; i < 4; i++)
		{
			int nrx = rx, nry = ry, nbx = bx, nby = by;

			while (board[nbx + dx[i]][nby + dy[i]] == '.')
			{
				nbx += dx[i];
				nby += dy[i];
			}
			if (board[nbx + dx[i]][nby + dy[i]] == 'O')
				continue;

			while (board[nrx + dx[i]][nry + dy[i]] == '.')
			{
				nrx += dx[i];
				nry += dy[i];
			}
			if (board[nrx + dx[i]][nry + dy[i]] == 'O')
				return cnt + 1;

			if ((nrx == nbx) && (nry == nby))
			{
				if (i == 0) // (-1, 0)
					rx < bx ? nbx++ : nrx++;
				else if (i == 1) // (0, -1) 
					ry < by ? nby++ : nry++;
				else if (i == 2) // (1, 0)
					rx < bx ? nrx-- : nbx--;
				else // (0, 1)
					ry < by ? nry-- : nby--;

			}
			if (dist[nrx][nry][nbx][nby] != -1) continue;
			dist[nrx][nry][nbx][nby] = cnt + 1;
			q.push({ nrx,nry,nbx,nby });
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;


	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < n; k++)
				fill(dist[i][j][k], dist[i][j][k] + m, -1);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'R')
			{
				rx = i; ry = j;
				board[i][j] = '.';
			}
			if (board[i][j] == 'B')
			{
				bx = i; by = j;
				board[i][j] = '.';
			}
		}

	cout << bfs();

	return 0;
}