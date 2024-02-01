#include<bits/stdc++.h>
using namespace std;

char board[12][6];
char visited[12][6];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

void resetv()
{
	for (int i = 0; i < 12; i++)
	{
		fill(visited[i], visited[i] + 6, false);
	}
}


bool bfs(int x, int y) // 4개 이상 뭉쳐있으면 true 아니면 false;
{
	resetv();
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[y][x] = true;
	int area = 1;
	char color = board[y][x];
	vector<pair<int,int>> coords;
	coords.push_back({ x,y });
	while (!q.empty())
	{
		auto [nx, ny] = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = nx + dx[i];
			int ty = ny + dy[i];
			if (tx < 0 || ty < 0 || tx >= 6 || ty >= 12) continue;
			if (visited[ty][tx] || board[ty][tx] != color) continue;
			visited[ty][tx] = true;
			area++;
			q.push({ tx,ty });
			coords.push_back({ tx,ty });
		}
	}

	if (area >= 4)
	{
		for (auto [x, y] : coords)
		{
			board[y][x] = '.';
		}
		return true;
	}
	else
	{
		for (auto [x, y] : coords)
		{
			board[y][x] = color;
		}
		return false;
	}

}

void updateboard()
{
	for (int x = 0; x < 6; x++)
	{
		int cur = 11;
		for (int y = 11; y >=0; y--)
		{
			if (board[y][x] == '.') continue;
			if (y == cur)
			{
				cur--;
				continue;
			}
			board[cur--][x] = board[y][x];
			board[y][x] = '.';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int combo = 0;
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cin >> board[i][j];
		}
	}
	bool isCrashed = true;
	while (isCrashed)
	{
		isCrashed = false; // 터진적이 한번이라도 있나?
		//일단 현재 상태에서 터져야 할건 다 터뜨린다.
		for (int i = 11; i >= 0; i--)
		{
			for (int j = 0; j < 6; j++)
			{
				if (board[i][j] != '.')
				{
					if (bfs(j, i))
					{
						isCrashed = true;
					}
				}
			}
		}
		updateboard(); // 보드 업데이트
		//for (int y = 0; y < 12; y++)
		//{
		//	for (int x = 0; x < 6; x++)
		//	{
		//		cout << board[y][x];
		//	}
		//	cout << '\n';
		//}
		//cout << '\n';
		if (isCrashed)combo++;
	}


	

	cout << combo;

	return 0;
}