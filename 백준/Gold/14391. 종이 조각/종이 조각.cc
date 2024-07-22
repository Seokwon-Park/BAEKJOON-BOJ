#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int b[4][4];
int c[4][4];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			b[i][j] = c - '0';
		}
	}
	int k = 1 << (n * m);
	int ans = 0;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n * m; j++)
		{
			if (i & (1 << j))
			{
				c[j / m][j % m] = 1;
			}
			else
			{
				c[j / m][j % m] = 0;
			}
		}

		int res = 0;
		for (int y = 0; y < n; y++)
		{
			int tmp = 0;
			for (int x = 0; x < m; x++)
			{
				if (c[y][x] == 1)
				{
					tmp = tmp * 10 + b[y][x];
				}
				else
				{
					res += tmp;
					tmp = 0;
				}
			}
			if (tmp) res += tmp;
		}

		for (int x = 0; x < m; x++)
		{
			int tmp = 0;
			for (int y = 0; y < n; y++)
			{
				if (c[y][x] == 0)
				{
					tmp = tmp * 10 + b[y][x];
				}
				else
				{
					res += tmp;
					tmp = 0;
				}
			}
			if (tmp) res += tmp;
		}

		ans = max(ans, res);
		//for (int r = 0; r < n; r++)
		//{
		//	for (int col = 0; col< m; col++)
		//	{
		//		cout << c[r][col];
		//	}
		//	cout << '\n';
		//}
	}
	cout << ans;

	return 0;
}