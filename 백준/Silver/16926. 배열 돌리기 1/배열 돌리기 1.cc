#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int b[305][305];
int bcpy[305][305];
int n, m, r;

void rotate(int x, int y, int w, int h)
{
	if (x >= m / 2 || y >= n / 2)
		return;
	int topleft= b[y][x];
	int topright = b[y][x+w-1];
	int botleft= b[y+h-1][x];
	int botright = b[y+h-1][x+w-1];

	// top
	for (int i = x; i < x + w - 1; i++)
		b[y][i] = b[y][i + 1];
	//left
	for (int i = y+h-1; i > y+1; i--)
		b[i][x] = b[i - 1][x];
	b[y + 1][x] = topleft;

	// bot
	for (int i = x+w-1; i > x+1; i--)
		b[y+h-1][i] = b[y+h-1][i - 1];
	b[y+h-1][x+1] = botleft;

	//right
	for (int i = y; i < y + h-2; i++)
	{
		b[i][x + w - 1] = b[i + 1][x + w - 1];
	}
	b[y + h - 2][x + w - 1] = botright;
	rotate(x + 1, y + 1, w-2, h-2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
			bcpy[i][j] = b[i][j];
		}
	}

	for (int i = 0; i < r; i++)
	{
		rotate(0, 0, m, n);
	}
	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << b[i][j] << ' ';
		}
		cout << '\n';
	}


	return 0;
}