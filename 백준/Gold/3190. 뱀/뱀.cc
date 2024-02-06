#include <bits/stdc++.h>

using namespace std;

// 0123 = 북동남서
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int dir = 1;
int tdir = 1;

int board[105][105];
int n, k, l;
unordered_map<int, char> dirflag;

int playgame()
{
	stack<vector<int>> s; // head x,y/ tail x, y
	s.push({ 0,0,0,0 });
	int sec = 0;
	int tsec = 0;
	while (!s.empty())
	{
		sec++;
		int hx = s.top()[0];
		int hy = s.top()[1];
		int tx = s.top()[2];
		int ty = s.top()[3];
		s.pop();

		int nx = hx + dx[dir];
		int ny = hy + dy[dir];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) return sec;
		if (board[ny][nx] == 1) return sec;
		if (board[ny][nx] == 2)
		{
			board[ny][nx] = 1;
		}
		else if (board[ny][nx] == 0)
		{
			board[ny][nx] = 1;
			board[ty][tx] = 0;
  			tsec++;
			tx = tx + dx[tdir];
			ty = ty + dy[tdir];
			if (dirflag[tsec] == 'L')
				tdir = (tdir + 3) % 4;
			else if (dirflag[tsec] == 'D')
				tdir = (tdir + 1) % 4;

		}
		s.push({ nx,ny,tx,ty });
		if (dirflag[sec] == 'L')
			dir = (dir + 3) % 4;
		else if (dirflag[sec] == 'D')
			dir = (dir + 1) % 4;

	}
	return sec;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int y, x;
		cin >> y >> x;
		board[y - 1][x - 1] = 2; // 사과를 보드에 그리기
	}
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int t;
		char c; // 시간과 회전 정보
		cin >> t >> c;
		dirflag[t] = c;
	}

	board[0][0] = 1; //뱀의 처음 위치와 길이.
	cout << playgame();

	return 0;
}
