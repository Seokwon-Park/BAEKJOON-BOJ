#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

char b[11][11];
char newb[11][11];
int r, c;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

bool isSea(int x, int y)
{
	if (x < 0 || y < 0 || x >= c || y >= r) return true;
	if (b[y][x] == '.')return true;
	return false;
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
			cin >> b[i][j];
			newb[i][j] = b[i][j];
		}
	}

	int mnx = INT_MAX;
	int mny = INT_MAX;
	int mxx = INT_MIN;
	int mxy = INT_MIN;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (b[i][j] == 'X')
			{
				int sea = 0;
				for (int k = 0; k < 4; k++)
				{
					if (isSea(j + dx[k], i + dy[k]))
						sea++;
				}
				if (sea >= 3)
				{

					newb[i][j] = '.';
				}
				else
				{
					mnx = min(mnx, j);
					mny = min(mny, i);
					mxx = max(mxx, j);
					mxy = max(mxy, i);
				}
			}
		}
	}

	for (int i = mny; i <= mxy; i++)
	{
		for (int j = mnx; j <= mxx; j++)
		{
			cout << newb[i][j];
		}
		cout << '\n';
	}

	return 0;
}