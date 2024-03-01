#include <bits/stdc++.h>

using namespace std;

bool visited[55][55];
char board[55][55];
int dist[55][55];
int w, h;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
vector<pair<int, int>> coord;

void resetv()
{
	for (int i = 0; i < h; i++)
	{
		fill(visited[i], visited[i] + w, false);
		fill(dist[i], dist[i] + w, 0);
	}
}

int bfs(int x, int y)
{
	resetv();
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[y][x] = true;
	int mxdist = INT_MIN;
	while (!q.empty())
	{
		auto [cx, cy] = q.front(); q.pop();
		mxdist = max(mxdist, dist[cy][cx]);
		for (int i = 0; i < 4; i++)
		{
			int tx = cx + dx[i];
			int ty = cy + dy[i];
			if (tx < 0 || ty < 0 || tx >= w || ty >= h) continue;
			if (board[ty][tx] == 'W' || visited[ty][tx]) continue;
			visited[ty][tx] = true;
			dist[ty][tx] = dist[cy][cx] + 1;
			q.push({ tx,ty });
		}
	}
	return mxdist;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> h >> w;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'L')
				coord.push_back({ j, i });
		}
	}

	int ans = INT_MIN;
	for (auto [x, y] : coord)
	{
		ans = max(bfs(x, y), ans);
	}

	cout << ans;

	return 0;
}