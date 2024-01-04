#include <bits/stdc++.h>

using namespace std;

int n, m;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

char board[1005][1005];
bool visited[1005][1005];
int f_dist[1005][1005];
int sg_dist[1005][1005];

void fire_bfs(vector<pair<int, int>>& fires)
{
	queue<pair<int, int>> q;

	for (auto f : fires)
	{
		q.push({ f.first,f.second });
		visited[f.second][f.first] = true;
	}

	while (!q.empty())
	{
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = nx + dx[i];
			int ty = ny + dy[i];
			if (tx < 0 || ty < 0 || tx >= n || ty >= m)continue;
			if (visited[ty][tx] || board[ty][tx] == '#') continue;
			visited[ty][tx] = true;
			f_dist[ty][tx] =  f_dist[ny][nx] + 1;
			q.push({ tx,ty });
		}
	}
}

bool sg_bfs(int x, int y) //상근 bfs라는 뜻
{
	for (int i = 0; i < m; i++)
	{
		fill(visited[i], visited[i] + n, false);
	}

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
			// target x, y;
			int tx = nx + dx[i];
			int ty = ny + dy[i];
			if (tx < 0 || ty < 0 || tx >= n || ty >= m) // 만약 맵에서 벗어났다면 탈출
			{
				cout << sg_dist[ny][nx] + 1 << '\n';
				return true;
			}
			if (visited[ty][tx] || board[ty][tx] == '#' || board[ty][tx] == '*') continue;
			if (f_dist[ty][tx] != 0 && f_dist[ty][tx] <= sg_dist[ny][nx] + 1) continue;// target x y에 불이 도달하는 시간보다 상근이가 도착하는 시간이 같거나 크면 못감
			sg_dist[ty][tx] = sg_dist[ny][nx] + 1;
			visited[ty][tx] = true;
			q.push({ tx,ty });
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		cin >> n >> m; // width, height;

		int sgx = 0, sgy = 0; //상근x, y;

		vector<pair<int, int>> fires;

		for (int i = 0; i < m; i++)
		{
			fill(board[i], board[i] + n, 0);
			fill(f_dist[i], f_dist[i] + n, 0);
			fill(sg_dist[i], sg_dist[i] + n, 0);
			fill(visited[i], visited[i] + n, false);
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> board[i][j];
			}
		}
		
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == '*')
				{
					fires.push_back({ j, i });
				}
				if (board[i][j] == '@')
				{
					sgx = j;
					sgy = i;
				}
			}
		}

		fire_bfs(fires);

		if (!sg_bfs(sgx, sgy)) // 탈출 못한경우(false 리턴)
		{
			cout << "IMPOSSIBLE\n";
		}

		//for (int i = 0; i < m; i++)
		//{
		//	for (int j = 0; j < n; j++)
		//	{
		//		cout << f_dist[i][j] << ' ';
		//	}
		//	cout << '\n';
		//}
	}

	return 0;
}
