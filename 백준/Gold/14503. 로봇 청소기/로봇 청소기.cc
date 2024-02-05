#include <bits/stdc++.h>

using namespace std;

// 0123 = 북동남서
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int board[55][55];
int n, m;
int x, y, dir;

bool isClean(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (board[ty][tx] == 0) return false; //청소되지 않은 칸이 있는 경우(벽이나 청소된 부분은 무시)

	}
	return true;
}

int clean(int x, int y)
{
	stack<pair<int, int>> s;
	s.push({ x,y });
	int cnt = 0;
	while (!s.empty())
	{
		auto [cx, cy] = s.top(); // curX, curY
		s.pop();
		if (!board[cy][cx]) // 1. 현재 칸을 청소한다.
		{
			board[cy][cx] = 2;
			cnt++; // 청소한 칸 수 기록.
		}
		if (isClean(cx, cy)) // 청소되지 않은 빈칸이 없는 경우(동서남북 벽(=1) 이나 청소된 부분(=2)면
		{
			int revdir = (dir + 2) % 4; //바라보는 방향을 유지한 채로 후진 방향.
			int tx = cx + dx[revdir];
			int ty = cy + dy[revdir];
			//후진 방향 좌표 잡기
			if (board[ty][tx] != 1) // 벽(=1) 이 아니면 후진한다.
			{
				s.push({ tx, ty });
			}
			else // 후진할 수 없다면 작동을 멈춘다.
			{
				return cnt;
			}
		}
		else// 청소하지 않은 빈칸이 있는 경우
		{
			dir = (dir + 3) % 4; // 반시계 방향으로 회전한다. (dir-1+4) %4
			int tx = cx + dx[dir]; // 바라보는 방향을 기준으로 앞쪽칸 좌표
			int ty = cy + dy[dir];
			if(board[ty][tx] == 0) // 청소 안된경우
				s.push({ tx, ty }); // 전진
			else
				s.push({ cx, cy }); // 회전만 한 상태로 1번으로.
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	cin >> y >> x >> dir;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j ++)
		{
			cin >> board[i][j];
		}
	}

	cout << clean(x, y) << '\n';

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		cout <<  board[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}

	return 0;
}