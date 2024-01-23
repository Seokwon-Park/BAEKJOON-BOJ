#include <bits/stdc++.h>

using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
#define INF 0x3f3f3f3f

int n, m, k;
int board[1005][1005];
int visited[1005][1005][11];
int d[1005][1005][11];

void bfs(int x, int y)
{
	queue<tuple<int, int, int>> q;
	q.push({ x,y, 0 });
	visited[y][x][0] = true;
	d[y][x][0] = 1;
	while (!q.empty())
	{
		auto [nx, ny, crash] = q.front();
		q.pop();
		if (ny == n - 1 && nx == m - 1) continue;
		for (int i = 0; i < 4; i++)
		{
			int tx = nx + dx[i];
			int ty = ny + dy[i];
			if (tx < 0 || ty < 0 || tx >= m || ty >= n) continue;
			if (board[ty][tx] == 1 && visited[ty][tx][crash-1]) continue;
			if (visited[ty][tx][crash]) continue;
			if (board[ty][tx])
			{
				if (crash < k)
				{
					visited[ty][tx][crash + 1] = true;
					d[ty][tx][crash + 1] = d[ny][nx][crash] + 1;
					q.push({ tx,ty,crash + 1 });
				}
				continue;
			}
			visited[ty][tx][crash] = true;
			d[ty][tx][crash] = d[ny][nx][crash] + 1;
			q.push({ tx,ty,crash});
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char input;
			cin >> input;
			board[i][j] = input - '0';
			fill(d[i][j], d[i][j] + k + 1, INF);
		}
	}

	bfs(0, 0);

	int answer = *min_element(d[n - 1][m - 1], d[n - 1][m - 1] + k + 1);
	if (answer == INF)
		cout << -1;
	else
		cout << answer;

	return 0;
}