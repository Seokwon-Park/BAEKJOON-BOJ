#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int board[4][5][5][5]; // dir, z, y, x;
int maze[5][5][5]; // z, y, x;
bool v[5][5][5];
int d[5][5][5];

int dx[6] = {-1,0,0,1,0,0};
int dy[6] = {0,-1,0,0,1,0};
int dz[6] = {0,0,-1,0,0,1};

int ans = INF;

void resetvd()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
		{
			fill(v[i][j], v[i][j] + 5, false);
			fill(d[i][j], d[i][j] + 5, false);
		}
}

void bfs()
{
	if (maze[0][0][0] == 0 || maze[4][4][4] == 0) return;
	resetvd();
	queue<tuple<int, int, int>> q;
	q.push({ 0,0,0 });
	v[0][0][0] = true;
	while (!q.empty())
	{
		int x, y, z;
		tie(x, y, z) = q.front(); q.pop();
		if (x == 4 && y == 4 && z == 4)
		{
			ans = min(ans, d[z][y][x]);
		}
		for (int i = 0; i < 6; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			int tz = z + dz[i];
			if (tx < 0 || ty < 0 || tz < 0 || tx >= 5 || ty >= 5 || tz >= 5)continue;
			if (v[tz][ty][tx] || !maze[tz][ty][tx]) continue;
			q.push(tie(tx, ty, tz));
			v[tz][ty][tx] = true;
			d[tz][ty][tx] = d[z][y][x] + 1;
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int z = 0; z < 5; z++)
	{
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				cin >> board[0][z][i][j];
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				board[1][z][j][4 - i] = board[0][z][i][j];
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				board[2][z][j][4 - i] = board[1][z][i][j];
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				board[3][z][j][4 - i] = board[2][z][i][j];
	}

	vector<int> order({0, 1, 2, 3, 4});
	do {
		for (int bf = 0; bf < 1024; bf++)
		{
			int tmp = bf;
			for (int i = 0; i < 5; i++)
			{
				int dir = tmp % 4;
				tmp /= 4;
				for (int y = 0; y < 5; y++)
					for (int x = 0; x < 5; x++)
						maze[i][y][x] = board[dir][order[i]][y][x];
			}
			bfs(); // 0, 0, 0에 대해서 bfs 돌린다.
		}
	} while (next_permutation(order.begin(), order.end()));

	if (ans == INF)
		cout << -1;
	else
		cout << ans;

	return 0;
}