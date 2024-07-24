#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int b[1005][1005];
int rows[1005];
int cols[1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, m;
		cin >> n >> m;
		fill(rows, rows + 1005, 0);
		fill(cols, cols+ 1005, 0);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> b[i][j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				rows[i] += b[i][j];
				cols[i] += b[j][i];
			}
		}

		for (int i = 0; i < m; i++)
		{
			int r1, c1, r2, c2, v;
			cin >> r1 >> c1 >> r2 >> c2 >> v;
			for (int r = r1-1; r < r2; r++)
			{
				rows[r] += v * (c2 - c1 + 1);
			}
			for (int c = c1 - 1; c < c2; c++)
			{
				cols[c] += v * (r2 - r1 + 1);
			}
		}

		//rows;
		for (int i = 0; i < n; i++)
		{
			cout << rows[i] << ' ';
		}
		cout << '\n';
		for (int i = 0; i < n; i++)
		{
			cout << cols[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}