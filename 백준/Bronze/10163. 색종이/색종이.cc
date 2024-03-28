#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int board[1005][1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int ix = 1; ix <= n; ix++)
	{
		int x, y, w, h;
		cin >> x >> y >> w >> h;
		for (int i = y; i < y+h; i++)
		{
			for (int j = x; j < x+w; j++)
			{
				board[i][j] = ix;
			}
		}
	}

	for (int ix = 1; ix <= n; ix++)
	{
		int cnt = 0;
		for (int i = 0; i < 1005; i++)
		{
			for (int j = 0; j < 1005; j++)
			{
				if (board[i][j] == ix)
					cnt++;
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}