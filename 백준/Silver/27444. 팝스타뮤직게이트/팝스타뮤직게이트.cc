#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int board[300000][9];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int b, x, n;
	cin >> b >> x >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> board[i][j];
		}
	}

	int result = 0;
	for (int j = 0; j < 9; j++)
	{
		bool islong = false;
		//check start is long note
		int st = 0;
		if (board[n-1][j] == 1)
		{
			while (st <n && board[n-1-st][j] == 1)st++;
			if (board[n-1-st][j] == 0 || st == n)
			{
				result += st * 100;
			}
			else // 2
			{
				st++;
				result += x* st /6;
			}
		}
		else if (board[n - 1][j] == 2)
		{
			if (board[n - 2][j] == 0)
			{
				st++;
				result += x * st / 6;
			}
		}
		int len = 0;
		for (int i = n - 1-st; i >= 0; i--)
		{
			if (board[i][j] == 0)
			{
				continue;
			}
			if (board[i][j] == 2)
			{
				len++;
				if (islong == false)
				{
					islong = true;
					result += 80;
				}
				else
				{
					islong = false;
					result += x * len / 6;
					len = 0;
				}
			}
			else if (board[i][j] == 1)
			{
				if (islong == true)
				{
					len++;
				}
				else
				{
					result += 100;
				}
			}
		}
		if (islong == true)
		{
			result += x * len / 6;
		}
	}
	cout << result;

	return 0;
}