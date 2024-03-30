#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int b[105][105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int m, n;
		cin >> m >> n;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> b[i][j];
			}
		}
		int move = 0;
		for (int x = 0; x < n; x++)
		{
			for (int y = m-1; y >=0; y--)
			{
				if (b[y][x] == false)
				{
					for (int k = y; k >= 0; k--)
					{
						if (b[k][x])
						{
							b[y][x] = true;
							b[k][x] = false;
							move += y - k;
							break;
						}
					}
				}
			}
		}
		cout << move << '\n';

	}

	return 0;
}