#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

ll arr[1005][1005];
ll update[1005][1005];
ll pfsum[1005][1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int t = 0; t < m; t++)
	{
		int j, r1, r2, c1, c2;
		cin >> j >> r1 >> c1 >> r2 >> c2;
		r1++;
		r2++;
		c1++;
		c2++;
		if (j == 1)
		{
			int k;
			cin >> k;
			update[r1][c1] += k;
			update[r1][c2 + 1] -= k;
			update[r2 + 1][c1] -= k;
			update[r2 + 1][c2 + 1] += k;
		}
		else
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					pfsum[i][j] = pfsum[i - 1][j] + pfsum[i][j - 1] - pfsum[i - 1][j - 1] + update[i][j];
				}
			}

			ll res = 0;
			for (int i = r1; i <= r2; i++)
			{
				for (int j = c1; j <= c2; j++)
				{
					res += arr[i][j] + pfsum[i][j];
				}
			}
			cout << res << '\n';
		}
	}

	return 0;
}