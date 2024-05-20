#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;

int n;
char b[11][11];
char played[11][11];
char ans[11][11];
int dx[8] = { -1, -1, -1,0,1,1,1,0 };
int dy[8] = { 1,0,-1,-1,-1,0,1,1 };
vector<pii> mines;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
			if (b[i][j] == '*')
				mines.push_back({ j, i });
			ans[i][j] = '.';
		}

	bool isBoom = false;
	for (int i = 0; i < n * n; i++)
	{
		cin >> played[i / n][i % n];
		if (played[i / n][i % n] == 'x')
		{
			if (b[i / n][i % n] == '*')
			{
				if (!isBoom)
				{
					for (auto [x, y] : mines)
						ans[y][x] = '*';
				}
				isBoom = true;
				continue;
			}
			int mine = 0;
			for (int k = 0; k < 8; k++)
			{
				int tx = i % n + dx[k];
				int ty = i / n + dy[k];
				if (tx < 0 || ty < 0 || tx >= n || ty >= n)continue;
				if (b[ty][tx] == '.') continue;
				mine++;
			}
			ans[i / n][i % n] = mine + '0';
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