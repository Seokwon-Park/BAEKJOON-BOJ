#include <bits/stdc++.h>

using namespace std;

bool board[105][105];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	while (n--)
	{
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		board[x][y] = true;

		vector<int> dcurv;
		dcurv.push_back(d);

		for (int i = 1; i <= g; i++)
		{
			for (int j = dcurv.size() - 1; j >= 0; j--)
			{
				dcurv.push_back((dcurv[j] + 1) % 4);
			}
		}

		for (int i = 0; i < dcurv.size(); i++)
		{
			int dir = dcurv[i];
			if (dir == 0)
			{
				x++;
			}
			if (dir == 1)
			{
				y--;
			}
			if (dir == 2)
			{
				x--;
			}
			if (dir == 3)
			{
				y++;
			}
			board[x][y] = true;
		}
	}
	int ans = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1]) ans++;
		}
	}

	cout << ans;


	return 0;
}