#include <bits/stdc++.h>

using namespace std;

int w, h, d; //width, height, depth ( x, y, z)
int sx, sy, sz;
int dx[6] = { -1,0,0,1,0,0 };
int dy[6] = { 0,-1,0,0,1,0 };
int dz[6] = { 0,0,-1,0,0,1 };

char board[35][35][35];
bool visited[35][35][35];
int dist[35][35][35];

bool bfs(int x, int y, int z) 
{
	for (int z = 0; z < d; z++)
	{
		for (int y = 0; y < h; y++)
		{
			fill(visited[z][y], visited[z][y] + w, false);
			fill(dist[z][y], dist[z][y] + w, 0);
		}
	}

	queue<vector<int>> q;
	q.push({ x,y,z });
	visited[z][y][x] = true;

	while (!q.empty())
	{
		int nx = q.front()[0];
		int ny = q.front()[1];
		int nz = q.front()[2];
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			// target x, y;
			int tx = nx + dx[i];
			int ty = ny + dy[i];
			int tz = nz + dz[i];
			if (tx < 0 || ty < 0 || tz < 0 || tx >= w || ty >= h || tz >= d) continue;
			if (visited[tz][ty][tx] || board[tz][ty][tx] == '#') continue;
			if (board[tz][ty][tx] == 'E')
			{
				cout << "Escaped in " << dist[nz][ny][nx] + 1 << " minute(s).\n";
				return true;
			}
			dist[tz][ty][tx] = dist[nz][ny][nx] + 1;
			visited[tz][ty][tx] = true;
			q.push({ tx,ty,tz });
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	char input;

	while (1)
	{
		cin >> d >> h >> w;
		if (!w && !h && !d) break;
		
		for (int z = 0; z < d; z++)
		{
			for (int y = 0; y < h; y++)
			{
				for (int x = 0; x < w; x++)
				{
					cin >> input;
					board[z][y][x] = input;
					if (input == 'S')
					{
						sx = x;
						sy = y;
						sz = z;
					}
				}
			}
		}

		if (!bfs(sx, sy, sz))
		{
			cout << "Trapped!\n";
		}

		//for (int z = 0; z < d; z++)
		//{
		//	for (int y = 0; y < h; y++)
		//	{
		//		for (int x = 0; x < w; x++)
		//		{
		//			cout << dist[z][y][x] << ' ';
		//		}
		//		cout << '\n';
		//	}
		//	cout << '\n';
		//}
	}

	return 0;
}