#include <bits/stdc++.h>

using namespace std;

const int MX = 3 * 1024;
char board[MX][MX *2];

void draw(int x, int y)
{
	board[x][y + 2] = '*';
	board[x+1][y + 1] = '*';
	board[x+1][y + 3] = '*';
	fill(board[x + 2] + y, board[x + 2] + y + 5, '*');
}

void func(int x, int y, int n)
{
	if (n == 3)
	{
		draw(x, y);
		return;
	}
	func(x, y + n / 2, n / 2);
	func(x + n/2 , y + n, n / 2);
	func(x + n/2, y, n / 2);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	for (int i = 0; i < MX; i++)
	{
		fill(board[i], board[i] + MX*2, ' ');
	}

	int n;
	cin >> n;
	func(0, 0, n);


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n*2; j++)
		{
			cout << board[i][j];
		}
		cout << '\n';
	}

	//cout << ans;

	return 0;
}