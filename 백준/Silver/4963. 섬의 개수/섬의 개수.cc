#include <bits/stdc++.h>

using namespace std;

int dx[8] = { -1,-1, 0,1,1,1, 0, -1 };
int dy[8] = { 0,-1,-1,-1,0,1, 1, 1 };


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (true)
	{
		int w, h;
		cin >> w >> h;

		if (w == 0 && h == 0) return 0;

		vector<vector<int>> board(h, vector<int>(w, 0));
		vector<vector<bool>> visited(h, vector<bool>(w, false));

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> board[i][j];
			}
		}

		int island = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (board[i][j] == 1 && !visited[i][j])
				{
					visited[i][j] = true;
					queue<pair<int, int>> q;
					q.push({ j ,i });
					while (!q.empty())
					{
						auto [x, y] = q.front(); q.pop();
						for (int i = 0; i < 8; i++)
						{
							int tx = x + dx[i];
							int ty = y + dy[i];
							if (tx < 0 || ty < 0 || tx >= w || ty >= h) continue;
							if (visited[ty][tx] || board[ty][tx] == 0) continue;
							q.push({ tx,ty });
							visited[ty][tx] = true;
						}
					}
					island++;
				}
			}
		}

		cout << island << '\n';
	}

	return 0;
}
