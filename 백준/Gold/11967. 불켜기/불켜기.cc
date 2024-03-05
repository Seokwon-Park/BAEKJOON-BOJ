#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

vector<pair<int, int>> swch[105][105];
int board[105][105];
bool visited[105][105];
bool isturnon[105][105];
int n, m;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

void resetv()
{
	for (int i = 0; i <= n; i++)
	{
		fill(visited[i], visited[i] + n + 1, false);
	}
}

int bfs()
{
	resetv();
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	visited[1][1] = true;
	int area = 1;
	while (!q.empty())
	{
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx < 1 || ty < 1 || tx > n || ty > n)continue;
			if (visited[ty][tx] || board[ty][tx] == 0) continue;
			area++;
			visited[ty][tx] = true;
			q.push({ tx,ty });
		}
		if (!isturnon[y][x])
		{
			isturnon[y][x] = true;
			for (auto [sx, sy] : swch[x][y])
			{
				board[sy][sx] = 1;
			}
		}
	}
	return area;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	board[1][1] = 1;
	for (int i = 0; i < m; i++)
	{
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		swch[x][y].push_back({ a, b });
	}

	int area = 0;
	bool isChanged = true;
	while (isChanged)
	{
		isChanged = false;
		int after = bfs();
		if (area != after)
		{
			area = after;
			isChanged = true;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (board[i][j] == 1)
				ans++;
		}
	cout << ans;
	return 0;
}
