#include <bits/stdc++.h>

using namespace std;

using ll = long long;

char board[105][105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int rcnt = 0;
	int ccnt = 0;
	for (int i = 0; i < n; i++)
	{
		int space = 0;
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == '.')
				space++;
			else
			{
				if (space >= 2)
					rcnt++;
				space = 0;
			}
		}
		if (space >= 2)
			rcnt++;
	}

	for (int i = 0; i < n; i++)
	{
		int space = 0;
		for (int j = 0; j < n; j++)
		{
			if (board[j][i] == '.')
				space++;
			else
			{
				if (space >= 2)
					ccnt++;
				space = 0;
			}
		}
		if (space >= 2)
			ccnt++;
	}

	cout << rcnt << ' ' << ccnt;


	return 0;
}