#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

char b[1000][1000];
char ans[1000][1000];
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (b[i][j] != '.')
				ans[i][j] = '*';
			else
			{
				int mine = 0;
				for (int k = 0; k < 8; k++)
				{
					int y = i + dy[k];
					int x = j + dx[k];
					if (y < 0 || x < 0 || y >= n || x >= n) continue;
					if (b[y][x] != '.')
					{
						mine += b[y][x] - '0';
					}
				}
				if (mine >= 10)
					ans[i][j] = 'M';
				else
					ans[i][j] = mine + '0';
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << ans[i][j];
		}
		cout << '\n';
	}


	return 0;
}