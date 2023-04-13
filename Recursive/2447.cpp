#include <bits/stdc++.h>

using namespace std;

char board[3000][3000];// 대충 3^7 커버가능한 범위

void recursive(int len, int x, int y)
{	
	if (len == 1)return;
	int partition = len / 3;
	for (int i = y; i < y + len; i++)
	{
		for (int j = x; j < x + len; j++)
		{
			if (i >= y+partition && j >= x+partition && i <= y + (2 * partition - 1) && j <= x + (2 * partition - 1))
			{
				board[i][j] = ' ';
			}
			else
				board[i][j] = '*';
		}
	}

	for (int i = y; i < y + len; i += partition)
		for (int j = x; j < x + len; j += partition)
		{
			if (!(i == y + partition && j == x + partition))
				recursive(partition, j, i);
		}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
			
	int n;
	cin >> n;
	
	recursive(n, 0, 0);//n 길이의 종이 0, 0에서 시작

	for (int i = 0; i <n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << board[i][j];
		}
		cout << '\n';
	}

	return 0;
}

