#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int n, m, r;
int b[105][105];
int bc[105][105];


void hSwap()
{
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < m; j++)
		{
			swap(b[i][j], b[n - i - 1][j]);
		}
	}
}

void wSwap()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m / 2; j++)
		{
			swap(b[i][j], b[i][m - j - 1]);
		}
	}
}

void rRight()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			bc[i][j] = b[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			b[j][n - i - 1] = bc[i][j];
		}
	}
	swap(n, m);
}

void rLeft()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			bc[i][j] = b[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			b[m - j - 1][i] = bc[i][j];
		}
	}
	swap(n, m);
}

void divRight()
{
	int halfn = n / 2;
	int halfm = m / 2;

	for (int i = 0; i < halfn; i++)
	{
		for (int j = 0; j < halfm; j++)
		{
			bc[i][j] = b[i][j];
		}
	}

	for (int i = 0; i < halfn; i++)
	{
		for (int j = 0; j < halfm; j++)
		{
			b[i][j] = b[i + halfn][j];
			b[i + halfn][j] = b[i + halfn][j + halfm];
			b[i + halfn][j + halfm] = b[i][j + halfm];
			b[i][j + halfm] = bc[i][j];
		}
	}
}

void dnc2()
{
	int halfn = n / 2;
	int halfm = m / 2;

	for (int i = 0; i < halfn; i++)
	{
		for (int j = 0; j < halfm; j++)
		{
			bc[i][j] = b[i][j];
		}
	}

	for (int i = 0; i < halfn; i++)
	{
		for (int j = 0; j < halfm; j++)
		{
			b[i][j] = b[i][j + halfm];
			b[i][j + halfm] = b[i + halfn][j + halfm];
			b[i + halfn][j + halfm] = b[i + halfn][j];
			b[i + halfn][j] = bc[i][j];
		}
	}
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
		}
	}

	for (int i = 0; i < r; i++)
	{
		int cmd;
		cin >> cmd;
		switch (cmd)
		{
		case 1:
			hSwap();
			break;
		case 2:
			wSwap();
			break;
		case 3:
			rRight();
			break;
		case 4:
			rLeft();
			break;
		case 5:
			divRight();
			break;
		case 6:
			dnc2();
			break;
		}
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
