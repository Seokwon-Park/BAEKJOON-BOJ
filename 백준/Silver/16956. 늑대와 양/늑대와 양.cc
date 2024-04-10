#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

char b[505][505];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int r, c;
	cin >> r >> c;
	int res = 1;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> b[i][j];
		}
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (b[i][j] == 'W')
			{
				for (int k = 0; k < 4; k++)
				{
					int tx = j + dx[k];
					int ty = i + dy[k];
					if (tx < 0 || ty < 0 || tx >= c || ty >= r || b[ty][tx] == 'W')continue;
					if (b[ty][tx] == 'S')
					{
						res = 0;
						break;
					}
					b[ty][tx] = 'D';
				}
			}
			if (res == 0)break;
		}
		if (res == 0)break;
	}

	if (res == 0)
		cout << 0;
	else
	{
		cout << 1 << '\n';
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cout << b[i][j];
			}
			cout << '\n';
		}
	}

	return 0;
}