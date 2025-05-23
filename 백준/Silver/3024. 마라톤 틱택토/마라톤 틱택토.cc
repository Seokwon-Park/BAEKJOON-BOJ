#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

char b[35][35];

bool chk(int x, int y, char& out)
{
	bool isWin = true;
	char ch;
	for (int i = 0; i < 3; i++)
	{
		ch = b[y+i][x];
		//row
		isWin = (ch != '.');
		for (int j = 0; j < 3; j++)
		{
			if (ch != b[y + i][x + j])
			{
				isWin = false;
				break;
			}
		}
		if (isWin)
		{
			out = ch;
			return true;
		}

		ch = b[y][x+i];
		//col
		isWin = (ch != '.');
		for (int j = 0; j < 3; j++)
		{
			if (ch != b[y + j][x + i])
			{
				isWin = false;
				break;
			}
		}
		if (isWin)
		{
			out = ch;
			return true;
		}
	}

	ch = b[y][x];
	isWin = (ch != '.');
	for (int i = 0; i < 3; i++)
	{
		if (ch != b[y + i][x + i])
		{
			isWin = false;
			break;
		}
	}
	if (isWin)
	{
		out = ch;
		return true;
	}

	ch = b[y][x+2];
	isWin = (ch != '.');
	for (int i = 0; i < 3; i++)
	{
		if (ch != b[y + i][x + 2 - i])
		{
			isWin = false;
			break;
		}
	}
	if (isWin)
	{
		out = ch;
		return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0;i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
		}
	}


	for (int i = 0; i < n-2; i++)
	{
		for (int j = 0; j < n-2; j++)
		{
			char ans;
			if(chk(j,i, ans))
			{
				cout << ans;
				return 0;
			}
		}
	}
	cout << "ongoing";
	

	return 0;
}