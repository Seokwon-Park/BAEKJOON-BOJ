#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

char b[205][205];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int r, c, n;
	cin >> r >> c >> n;
	vector<pii> v;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> b[i][j];
			if (b[i][j] == 'O')
				v.push_back({ j,i });
		}
	}

	if (n == 1)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cout << b[i][j];
			}
			cout << '\n';
		}
	}
	else if (n % 2 == 0)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cout << 'O';
			}
			cout << '\n';
		}
	}
	else if (n % 4 == 1)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				b[i][j] = 'O';
			}
		}

		for (int i = 0; i < v.size(); i++)
		{
			auto [x, y] = v[i];
			b[y][x] = '.';
			if (x + 1 < c)
				b[y][x + 1] = '.';
			if (y + 1 < r)
				b[y + 1][x] = '.';
			if (x - 1 >= 0)
				b[y][x - 1] = '.';
			if (y - 1 >= 0)
				b[y - 1][x] = '.';
		}
		vector<pii> tmp;

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (b[i][j] == 'O')
					tmp.push_back({ j,i });
			}
		}

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				b[i][j] = 'O';
			}
		}

		for (int i = 0; i < tmp.size(); i++)
		{
			auto [x, y] = tmp[i];
			b[y][x] = '.';
			if (x + 1 < c)
				b[y][x + 1] = '.';
			if (y + 1 < r)
				b[y + 1][x] = '.';
			if (x - 1 >= 0)
				b[y][x - 1] = '.';
			if (y - 1 >= 0)
				b[y - 1][x] = '.';
		}

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cout << b[i][j];
			}
			cout << '\n';
		}
	}
	else if (n % 4 == 3)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				b[i][j] = 'O';
			}
		}

		for (int i = 0; i < v.size(); i++)
		{
			auto [x, y] = v[i];
			b[y][x] = '.';
			if (x + 1 < c)
				b[y][x + 1] = '.';
			if (y + 1 < r)
				b[y + 1][x] = '.';
			if (x - 1 >= 0)
				b[y][x - 1] = '.';
			if (y - 1 >= 0)
				b[y - 1][x] = '.';
		}

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cout << b[i][j];
			}
			cout << '\n';
		}
	}



	return 0;
}