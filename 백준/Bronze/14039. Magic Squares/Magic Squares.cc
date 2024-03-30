#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int board[4][4];
int row[4];
int col[4];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	bool isMagic = true;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> board[i][j];
			row[i] += board[i][j];
			col[j] += board[i][j];
		}
	}

	for (int i = 1; i < 4; i++)
	{
		if (row[0] != row[i] || col[0] != col[i])
		{
			isMagic = false;
			break;
		}
	}

	if (isMagic)
		cout << "magic";
	else
		cout << "not magic";

	return 0;
}