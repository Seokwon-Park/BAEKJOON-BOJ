#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int b[19][19];
int checked[19][19];

bool check(int x, int y)
{
	int color = b[y][x];
	int cnt = 1;
	bool isWin = false;
	if (x + 4 < 19 && y >= 4)
	{
		for (int i = 1; i < 5; i++)
		{
			if (b[y - i][x + i] == color) 
				cnt++;
			else
				break;
		}
		if (cnt == 5)
		{
			isWin = true;
			if (x + 5 < 19 && y - 5 >= 0)
				if (b[y - 5][x + 5] == color)
					isWin = false;
			if (x - 1 >= 0 && y + 1 < 19)
				if (b[y + 1][x - 1] == color)
					isWin = false;
		}
		if (isWin) return true;
	}
	cnt = 1;
	if (x + 5 <= 19)
	{
		for (int i = x + 1; i < x + 5; i++)
		{
			if (b[y][i] == color)
				cnt++;
			else
				break;
		}
		if (cnt == 5)
		{
			isWin = true;
			if (x - 1 >= 0)
				if (b[y][x - 1] == color)
					isWin = false;
			if (x + 6 <= 19)
				if (b[y][x + 5] == color)
					isWin = false;
		}
		if (isWin) return true;
	}
	cnt = 1;
	if (y + 5 <= 19)
	{
		for (int i = y + 1; i < y + 5; i++)
		{
			if (b[i][x] == color)
				cnt++;
			else
				break;
		}
		if (cnt == 5)
		{
			isWin = true;
			if (y - 1 >= 0)
				if (b[y-1][x] == color)
					isWin = false;
			if (y + 6 <= 19)
				if (b[y+5][x] == color)
					isWin = false;
		}
		if (isWin) return true;
	}
	cnt = 1;
	if (x + 5 <= 19 && y + 5 <= 19)
	{
		for (int i = 1; i < 5; i++)
		{
			if (b[y + i][x + i] == color)
				cnt++;
		}
		if (cnt == 5)
		{
			isWin = true;
			if (x - 1 >= 0 && y-1 >=0)
				if (b[y -1][x - 1] == color)
					isWin = false;
			if (x + 6 <= 19 && y + 6 <= 19)
				if (b[y + 5][x + 5] == color)
					isWin = false;
		}
	}
	return isWin;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			cin >> b[i][j];
		}
	}

	int winner = 0;
	int leftx = 19;
	int lefty = 19;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (b[i][j] != 0)
			{
				if (check(j, i))
				{
					if (j < leftx)
 					{
						leftx = j;
						lefty = i;
						winner = b[i][j];
					}
					else if (j == leftx)
					{
						if (i < lefty)
						{
							leftx = j;
							lefty = i;
							winner = b[i][j];
						}

					}
				}
				
			}
		}
	}
	if (winner)
	{
		cout << winner << '\n';
		cout << lefty+1 << ' ' << leftx + 1;
	}
	else
	{
		cout << winner;
	}

	return 0;
}