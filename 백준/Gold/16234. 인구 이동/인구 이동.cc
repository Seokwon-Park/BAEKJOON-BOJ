#include <bits/stdc++.h>

using namespace std;

int n, l, r;
int board[55][55];
bool visited[55][55];

void resetv()
{
	for (int i = 0; i < n; i++)
	{
		fill(visited[i], visited[i] + n, false);
	}
}

bool bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[y][x] = true;
	int sum = board[y][x];
	vector<pair<int, int>> coords(1, { x,y });
	bool isMoved = false;
	while (!q.empty())
	{
		auto [cx, cy] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = cx + "0121"[i] - '1';
			int ty = cy + "1012"[i] - '1';
			if (visited[ty][tx]) continue;
			if (tx < 0 || ty < 0 || tx >= n || ty >= n) continue;
			int gap = abs(board[cy][cx] - board[ty][tx]);
			if (gap <l || gap > r) continue;
			isMoved = true;
			visited[ty][tx] = true;
			coords.push_back({ tx,ty });
			sum += board[ty][tx];
			q.push({ tx,ty });
		}
	}

	if (isMoved)
	{
		int res = sum / coords.size();
		for (auto [cx, cy] : coords)
		{
			board[cy][cx] = res;
		}
	}
	return isMoved;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> l >> r;

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	
	bool chk = true;
	while (chk)
	{
		chk = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visited[i][j])
					chk |= bfs(j, i);
			}
		}
		resetv();
		if (chk) ans++;
	}

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		cout << board[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}

	cout << ans;

	return 0;
}