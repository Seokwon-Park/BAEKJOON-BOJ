#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int r, c;
int zr, zc;
char board[55][55];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> r >> c >> zr >> zc;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < r * zr; i++)
	{
		for (int j = 0; j < c * zc; j++)
		{
			cout << board[i/zr][j/zc];
		}
		cout << '\n';
	}

	return 0;
}