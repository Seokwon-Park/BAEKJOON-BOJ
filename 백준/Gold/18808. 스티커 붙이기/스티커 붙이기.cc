#include <bits/stdc++.h>

using namespace std;

int stk[15][15];
int paper[45][45];
int n, m, k;
int r, c;

bool is_paste(int x, int y)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (paper[y + i][x + j] == 1 && stk[i][j] == 1)
				return false;
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (stk[i][j] == 1)
			{
				paper[y + i][x + j] = 1;
			}
		}
	}
	return true;
}

void rotate()
{
	int nstk[15][15];
	for (int j = 0; j < r; j++)
		for (int k = 0; k < c; k++)
		{
			nstk[k][r - j - 1] = stk[j][k];
		}
	swap(r, c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			stk[i][j] = nstk[i][j];
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{

		cin >> r >> c;
		for (int j = 0; j < r; j++)
			for (int k = 0; k < c; k++)
			{
				cin >> stk[j][k];
			}

		for (int j = 0; j < 4; j++)
		{
			bool chk = false;
			for (int y = 0; y <= n - r; y++)
			{
				if (chk) break; // 붙었으면 break;
				for (int x = 0; x <= m - c; x++)
				{
					if (is_paste(x, y)) // 붙일 수 있으면 붙인다.
					{
						chk = true;
						break;
					}
				}
			}
			if (chk) break; // 붙었으면 break;
			rotate();
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cnt+=paper[i][j];
		}
	}
	cout << cnt << '\n';

	return 0;
}