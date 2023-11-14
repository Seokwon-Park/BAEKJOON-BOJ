#include <bits/stdc++.h>

using namespace std;

vector<string> bw = { string("BWBWBWBW"), string("WBWBWBWB") };
vector<string> wb = { string("WBWBWBWB"), string("BWBWBWBW") };

char board[55][55];

int chkBW(int i, int j)
{
	int count = 0;
	for (int a = i; a < i + 8; a++)
		for (int b = j; b < j + 8; b++)
		{
			if (board[a][b] != bw[a % 2][b-j])
				count++;
		}
	return count;
}

int chkWB(int i, int j)
{
	int count = 0;
	for (int a = i; a < i + 8; a++)
		for (int b = j; b < j + 8; b++)
		{
			if (board[a][b] != wb[a % 2][b-j])
				count++;
		}
	return count;
}

int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);


	int n, m;
	cin >> n >> m;
	int minval = INT_MAX;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i <= n - 8; i++)
	{
		for (int j = 0; j <= m - 8; j++)
		{
			int bwc = chkBW(i, j);
			int wbc = chkWB(i, j);
			minval = min(minval, min(bwc, wbc));
		}
	}

	cout << minval;

	return 0;
}