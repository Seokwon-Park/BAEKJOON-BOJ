#include <bits/stdc++.h>

using namespace std;

using ll = long long;

char b[400][400];

void func(int n, int x, int y)
{
	if (n == 1)
	{
		b[y][x] = '*';
		return;
	}
	for (int i = x; i < x+1 + (n - 1) * 4; i++)
	{
		b[y][i] = '*';
		b[y + (n - 1) * 4][i] = '*';
	}

	for (int i = y + 1; i < y + (n - 1) * 4; i++)
	{
		b[i][x] = '*';
		b[i][x + (n - 1) * 4] = '*';
	}
	

	func(n - 1, x + 2, y + 2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	

	for (int i = 0; i < 1 + (n - 1) * 4; i++)
		fill(b[i], b[i] + 1 + (n - 1) * 4, ' ');

	func(n, 0, 0);

	for (int i = 0; i < 1 + (n - 1) * 4; i++)
	{
		for (int j = 0; j < 1 + (n - 1) * 4; j++)
		{
			cout << b[i][j];
		}
		cout << '\n';
	}

	
	return 0;
}