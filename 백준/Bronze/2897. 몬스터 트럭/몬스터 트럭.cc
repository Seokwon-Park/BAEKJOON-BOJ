#include <bits/stdc++.h>

using namespace std;

using ll = long long;

char b[55][55];

int canPark(int y, int x)
{
	int crash = 0;
	for(int i = y; i <y+2; i++)
		for (int j = x; j < x + 2; j++)
		{
			if(b[i][j] == '#')return -1;
			if (b[i][j] == 'X') crash++;
		}
	return crash;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> b[i][j];
		}
	}

	vector<int> park(5, 0);
	for (int i = 0; i < r-1; i++)
	{
		for (int j = 0; j < c-1; j++)
		{
			int res = canPark(i, j);
			if (res == -1) continue;
			else
				park[res]++;
		}
	}
	for (int i : park)
		cout << i << '\n';

	return 0;
}