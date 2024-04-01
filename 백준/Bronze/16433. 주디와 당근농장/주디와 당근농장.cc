#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, r, c;
	cin >> n >> r >> c;
	int row = (r - 1) % 2;
	int col = (c - 1) % 2;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i % 2 == row)
			{
				if (j % 2 == col)
					cout << 'v';
				else
					cout << '.';
			}
			else
			{
				if (j % 2 == col)
					cout << '.';
				else
					cout << 'v';
			}
		}
		cout << '\n';
	}

	return 0;
}