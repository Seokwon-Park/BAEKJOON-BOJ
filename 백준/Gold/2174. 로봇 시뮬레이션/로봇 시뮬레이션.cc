#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int board[105][105];
tuple<int, int, int> robot[105];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int ctodir(char c)
{
	if (c == 'W')
		return 0;
	else if (c == 'N')
		return 1;
	else if (c == 'E')
		return 2;
	else // S
		return 3;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	int n, m;
	cin >> a >> b >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		int x, y;
		char cdir;
		cin >> x >> y >> cdir;

		int dir = ctodir(cdir);
		robot[i] = tie(x, y, dir);
		board[x][y] = i;
	}

	vector<tuple<int, char, int>>v(m);
	for (int i = 0; i < m; i++)
	{
		int ix, repeat;
		char cmd;
		cin >> ix >> cmd >> repeat;
		v[i] = tie(ix, cmd, repeat);
	}

	for (int i = 0; i < m; i++)
	{
		int ix, repeat;
		char cmd;
		tie(ix, cmd, repeat) = v[i];
		int x, y, dir;
		tie(x, y, dir) = robot[ix];
		if (cmd == 'F')
		{
			for (int j = 0; j < repeat; j++)
			{
				int tx = x + dx[dir];
				int ty = y + dy[dir];
				if (tx < 1 || ty < 1 || tx > a || ty > b)
				{
					cout << "Robot " << ix << " crashes into the wall";
					return 0;
				}
				else if (board[tx][ty] != 0)
				{
					cout << "Robot " << ix << " crashes into robot " << board[tx][ty];
					return 0;
				}
				board[x][y] = 0;
				board[tx][ty] = 1;
				x = tx;
				y = ty;
			}
			robot[ix] = tie(x, y, dir);
		}
		else if (cmd == 'L')
		{
			for (int j = 0; j < repeat; j++)
				dir = (dir + 3) % 4;
			robot[ix] = tie(x, y, dir);
		}
		else
		{
			for (int j = 0; j < repeat; j++)
				dir = (dir + 1) % 4;
			robot[ix] = tie(x, y, dir);
		}
	}

	cout << "OK";

	return 0;
}