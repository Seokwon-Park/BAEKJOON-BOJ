#include <bits/stdc++.h>

using namespace std;

char b[55][55];
char b2[105][105];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> b[i][j];
			b2[i][j] = b[i][j];
			b2[i][c * 2 - 1 - j] = b[i][j];
			b2[r*2-1-i][j] = b[i][j];
			b2[r * 2 - 1 - i][c * 2 - 1 - j] = b[i][j];
		}
	}
	int y, x;
	cin >> y >> x;

	b2[y - 1][x - 1] = (b2[y - 1][x - 1] == '#' ? '.' : '#');

	for (int i = 0; i < r*2; i++)
	{
		for (int j = 0; j < c*2; j++)
		{
			cout << b2[i][j];
		}
		cout << '\n';
	}

	return 0;
}