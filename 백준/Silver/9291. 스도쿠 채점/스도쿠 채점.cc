#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int b[9][9];

bool checkRow()
{
	for (int r = 0; r < 9; r++)
	{
		vector<bool> isChecked(10, false);
		for (int c = 0; c < 9; c++)
		{
			if (isChecked[b[r][c]])
				return false;
			isChecked[b[r][c]] = true;
		}
	}
	return true;
}

bool checkCol()
{
	for (int c = 0; c < 9; c++)
	{
		vector<bool> isChecked(10, false);
		for (int r = 0; r < 9; r++)
		{
			if (isChecked[b[r][c]])
				return false;
			isChecked[b[r][c]] = true;
		}
	}
	return true;
}

bool checkBox()
{
	for (int i = 0; i < 9; i++)
	{
		vector<bool> isChecked(10, false);
		int rs = (i / 3)*3;
		int cs = (i % 3)*3;
		for (int r = 0; r < 3; r++)
		{
			for (int c = 0; c < 3; c++)
			{
				if (isChecked[b[rs+r][cs+c]])
					return false;
				isChecked[b[rs+r][cs+c]] = true;
			}
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		for (int r = 0; r < 9; r++)
		{
			for (int c = 0; c < 9; c++)
			{
				cin >> b[r][c];
			}
		}

		cout << "Case " << i << ": ";
		if (!checkRow() || !checkCol() || !checkBox())
			cout << "INCORRECT";
		else
			cout << "CORRECT";
		cout << "\n";
	}


	return 0;
}