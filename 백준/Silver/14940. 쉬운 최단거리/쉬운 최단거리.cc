#include <bits/stdc++.h>

using namespace std;

bool visited[1005][1005];
int dist[1005][1005];
int board[1005][1005];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int n, m;


void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[y][x] = true;
	while (!q.empty())
	{
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = nx + dx[i];
			int ty = ny + dy[i];
			if (tx < 0 || ty < 0 || tx >= m || ty >= n)continue;
			if (board[ty][tx] == 0 || visited[ty][tx]) continue;
			q.push({ tx,ty });
			visited[ty][tx] = true;
			dist[ty][tx] = dist[ny][nx] + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x, y;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		fill(dist[i], dist[i] + m, -1);
		for (int j = 0; j < m; j ++)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
			{
				x = j; y = i;
			}
			if (board[i][j] == 0)
			{
				dist[i][j] = 0;
			}
		}
	}

	dist[y][x] = 0;
	bfs(x, y);
	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{	
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}


	return 0;
}
