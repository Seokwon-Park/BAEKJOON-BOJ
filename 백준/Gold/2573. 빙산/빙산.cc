#include <bits/stdc++.h>

using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int board[305][305];
int newbd[305][305];
bool visited[305][305];
int n, m;

void melt(int x, int y)
{
	int val = 0;
	for (int i = 0; i < 4; i++)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 0 || ty < 0 || tx >= m || ty >= n) continue;
		if (board[ty][tx] != 0) continue;
		val++;
	}
	newbd[y][x] = (board[y][x] - val) < 0? 0 : board[y][x] - val;
}

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[y][x] = true;
	while (!q.empty())
	{
		int nx = q.front().first;
		int ny= q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = nx + dx[i];
			int ty = ny + dy[i];
			if (tx < 0 || ty < 0 || tx >= m || ty >= n) continue;
			if (visited[ty][tx]) continue;
			q.push({ tx,ty });
			visited[ty][tx] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i =0; i< n; i ++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 0)
				visited[i][j] = true;
			else
				visited[i][j] = false;
		}
	}
		
	int year = 0;
	int res = 0;
	while (true)
	{
		res = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] != 0 && !visited[i][j])
				{
					bfs(j, i);
					res++;
				}
			}
		}

		if (res >= 2) break;
		else if (res == 0)break;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if(board[i][j] != 0)
					melt(j, i);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				board[i][j] = newbd[i][j];
				if (board[i][j] == 0)
					visited[i][j] = true;
				else
					visited[i][j] = false;
				//cout << board[i][j] << ' ';
			}
			//cout << '\n';
		}
		year++; 
	}

	if (res == 0)
		cout << 0;
	else
		cout << year;

	return 0;
}