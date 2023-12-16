#include <bits/stdc++.h>

using namespace std;

int board[55][55];
int correct[55][55];

void rev3x3(int y, int x)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[y + i][x + j] == 0)
				board[y + i][x + j] = 1;
			else 
				board[y + i][x + j] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int answer = 0;

	for (int i = 0; i < n; i++)
	{
		string line;
		cin >> line;
		for (int j = 0; j< m; j++)
		{
			board[i][j] = line[j]-'0';
		}
	}

	for (int i = 0; i < n; i++)
	{
		string line;
		cin >> line;
		for (int j = 0; j < m; j++)
		{
			correct[i][j] = line[j] - '0';
		}
	}

	for (int i = 0; i < n-2; i++)
	{
		for (int j = 0; j < m-2; j++)
		{
			if (board[i][j] != correct[i][j])
			{
				rev3x3(i, j);
				answer++;
			}
		}
	}

	bool check = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] != correct[i][j])
			{
				check = false;
			}
		}
	}

	if (check)
	{
		cout << answer;
	}
	else if (n < 3 || m < 3)
	{
		cout << -1;
	}
	else
	{
		cout << -1;
	}

	return 0;
}