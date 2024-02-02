#include<bits/stdc++.h>
using namespace std;

int n, m, y, x, k;
int board[25][25];
int dice[6];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};


// 0 = top, 1 = north, 2 = east, 3 west, 4 south, 5 bottom;
int update(int dir) // return bottom value, after rolling
{
	int temp = dice[0];
	switch (dir)
	{
	case 1:
		dice[0] = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[2];
		dice[2] = temp;
		break;
	case 2:
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[5] = dice[3];
		dice[3] = temp;
		break;
	case 3:
		dice[0] = dice[4];
		dice[4] = dice[5];
		dice[5] = dice[1];
		dice[1] = temp;
		break;

	case 4:
		dice[0] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[4];
		dice[4] = temp;
		break;
	}
	return dice[5];
}

int roll(int xx, int yy, int dir)
{
	int i = dir - 1;
	int tx = xx + dx[i];
	int ty = yy + dy[i];
	if (tx < 0 || ty < 0 || tx >= m || ty >= n) return -1;
	int bot = update(dir);
	if (board[ty][tx] == 0)
	{
		board[ty][tx] = bot;
	}
	else
	{
		dice[5] = board[ty][tx];
		board[ty][tx] = 0;
	}
	
	return ty * m + tx;
}
//index = 0 : 12시 | = 2: 3시 | = 4 : 6시 | = 6: 9시
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> y >> x >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < k; i++)
	{
		int dir;
		cin >> dir;
		int xy = roll(x, y, dir);
		if (xy != -1)
		{
			x = xy % m;
			y = xy / m;
			cout << dice[0] << '\n';
		}
	}

	

	return 0;
}