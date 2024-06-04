#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int n;
char b[100][100];

void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << b[i][j];
		}
		cout << '\n';
	}
}

void flip(bool isVertical)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n/2; j++)
		{
			if (isVertical)
				swap(b[j][i], b[n - 1 - j][i]);
			else
				swap(b[i][j], b[i][n - 1 - j]);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
		}
	}

	int cmd;
	cin >> cmd;

	if (cmd == 1)
	{
		print();
	}
	else if (cmd == 2)
	{
		flip(false);
		print();
	}
	else
	{
		flip(true);
		print();
	}


	return 0;
}