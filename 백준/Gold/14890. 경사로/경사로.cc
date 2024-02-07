
#include <bits/stdc++.h>

using namespace std;

int n, l;
int board[105][105];
int newb[105][105];

void rotate()
{
	// copy
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			newb[i][j] = board[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			board[j][n-i-1] = newb[i][j];
}

bool isRoute(int row)
{
	int ix = 0;
	int len = 1;
	while (ix < n - 1)
	{
		if (abs(board[row][ix + 1] - board[row][ix]) > 1)return false;
		if (board[row][ix] == board[row][ix + 1])
		{
			ix++;
			len++;
		}
		else if (board[row][ix] < board[row][ix + 1])
		{
			if (len < l) return false;
			len = 1;
			ix++;
		}
		else
		{
			if (ix + l >= n) return false;
			for(int i = ix+1; i< ix+l; i++)
				if (board[row][i] != board[row][i + 1]) return false;
			ix += l;
			len = 0;
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	int ans = 0;
	for (int r = 0; r < 2; r++)
	{
		for (int i = 0; i < n ;i ++)
		{
			if (isRoute(i))
			{
				ans++;
				//cout << i << " is route\n";
			}
		}
		rotate();
	}


	cout << ans;


	return 0;
}