#include <bits/stdc++.h>

using namespace std;

int n, m;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

char board[605][605];
bool visited[605][605];

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[y][x] = true;

	int meet = 0;
	while (!q.empty())
	{
		int nx = q.front().first;
		int ny = q.front().second;
		if (board[ny][nx] == 'P')
		{
			meet++;
		}
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = nx + dx[i];
			int ty = ny + dy[i];
			if (tx < 0 || ty < 0 || tx >= m || ty >= n)continue;
			if (visited[ty][tx] || board[ty][tx] == 'X') continue;
			visited[ty][tx] = true;
			q.push({ tx,ty });
		}
	}
	if (meet == 0)
		cout << "TT";
	else
		cout << meet;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 'I')
			{
				bfs(j, i);
			}
		}
	}



	return 0;
}
