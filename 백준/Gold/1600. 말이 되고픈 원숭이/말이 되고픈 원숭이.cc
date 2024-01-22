#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int jx[8] = { -2,-1, 1, 2, 2,1, -1, -2 };
int jy[8] = { -1,-2, -2,-1, 1, 2, 2, 1 };

int board[205][205];
int visited[205][205][35];
int dist[205][205][35]; // 이 좌표로 내려오는 방법의 수
int k;
int w, h;

bool is_in_bound(int tx, int ty)
{
	if (tx < 0 || ty < 0 || tx >= w || ty >= h) return false;
	return true;
}

void bfs(int x, int y)
{
	queue<tuple<int, int, int>> q;
	q.push({ x, y, 0 });
	dist[y][x][0] = 0;
	while (!q.empty())
	{
		auto [nx, ny, jump] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = nx + dx[i];
			int ty = ny + dy[i];
			if (!is_in_bound(tx, ty) || visited[ty][tx][jump] || board[ty][tx] == 1) continue;
			visited[ty][tx][jump] = true;
			dist[ty][tx][jump] = dist[ny][nx][jump] + 1;
			q.push({ tx, ty, jump });
		}
		if (jump < k)
			for (int i = 0; i < 8; i++)
			{
				int tx = nx + jx[i];
				int ty = ny + jy[i];
				if (!is_in_bound(tx, ty) || visited[ty][tx][jump + 1] || board[ty][tx] == 1) continue;
				visited[ty][tx][jump + 1] = true;
				dist[ty][tx][jump + 1] = dist[ny][nx][jump] + 1;
				q.push({ tx, ty, jump + 1 });
			}
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> k;
	cin >> w >> h;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> board[i][j];
			for (int l = 0; l <= k; l++)
			{
				dist[i][j][l] = INF;
			}
		}
	}

	bfs(0, 0);

	int answer = *min_element(dist[h - 1][w - 1], dist[h - 1][w - 1] + k + 1);
	if (answer == INF)
		cout << -1;
	else
		cout << answer;
	return 0;
}