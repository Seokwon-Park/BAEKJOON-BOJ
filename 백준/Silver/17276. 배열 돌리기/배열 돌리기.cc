#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int b[505][505];
int bb[505][505];
int n, d;

void R()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				bb[i][(n + 1) / 2] = b[i][j];
			}
			if (j == (n + 1) / 2)
			{
				bb[i][n - i + 1] = b[i][j];
			}
			if (i + j == n + 1)
			{
				bb[(n + 1) / 2][j] = b[i][j];
			}
			if (i == (n + 1) / 2)
			{
				bb[j][j] = b[i][j];
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			b[i][j] = bb[i][j];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> b[i][j];
				bb[i][j] = b[i][j];
			}
		}

		int rotate = d / 45;
		if (rotate < 0) rotate += 8;
		rotate %= 8;

		while (rotate--)
		{
			R();
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cout << b[i][j] << ' ';
			}
			cout << '\n';
		}

 	}



	return 0;
}