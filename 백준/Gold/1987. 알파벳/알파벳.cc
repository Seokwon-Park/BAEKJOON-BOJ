#include <bits/stdc++.h>

using namespace std;

int r, c;
char board[25][25];
bool isUsed[26];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int mx = 1;
int len = 1;

void func(int x, int y)
{
	int idx = board[y][x] - 'A';
	if (!isUsed[idx])
		isUsed[idx] = true;
	else
	{
		mx = max(mx, len - 1);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 0 || ty < 0 || tx >= c || ty >= r) continue;
		len++;
		func(tx, ty);
		len--;
	}
	isUsed[idx] = false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> board[i][j];
		}
	}

	func(0, 0);

	cout << mx;
	
	return 0;
}