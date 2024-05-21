#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;

int b[9][9];
bool row[9][10];
bool col[9][10];
bool sq[9][10];
// 0 1 2
// 3 4 5
// 6 7 8
vector<pii> v;

void func(int k)
{
	if (k == v.size())
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << b[i][j];
			}
			cout << '\n';
		}
		exit(0);
	}
	auto [x, y] = v[k];
	for (int i = 1; i <= 9; i++)
	{
		if (row[y][i] || col[x][i] || sq[y / 3 * 3 + x / 3][i]) continue;
		row[y][i] = true;
		col[x][i] = true;
		sq[y / 3 * 3 + x / 3][i] = true;
		b[y][x] = i;
		func(k + 1);
		b[y][x] = 0;
		row[y][i] = false;
		col[x][i] = false;
		sq[y / 3 * 3 + x / 3][i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			char c;
			cin >> c;
			b[i][j] = c - '0';
			if (b[i][j] == 0)
				v.push_back({ j,i });
			else
			{
				row[i][b[i][j]] = true;
				col[j][b[i][j]] = true;
				sq[i / 3 * 3 + j / 3][b[i][j]] = true;
			}
		}
	}

	func(0);

	return 0;
}