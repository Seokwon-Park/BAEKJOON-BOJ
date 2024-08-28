#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int b[2005][2005];
int bw[2005][2005];
int wb[2005][2005];

int prebw[2005][2005];
int prewb[2005][2005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char ch;
			cin >> ch;
			if (ch == 'B')
			{
				b[i][j] = 1;
			}
			else
			{
				b[i][j] = 0;
			}

			if (i % 2 == 1)
			{
				bw[i][j] = (j % 2 == 1);
				wb[i][j] = (j % 2 == 0);
			}
			else
			{
				bw[i][j] = (j % 2 == 0);
				wb[i][j] = (j % 2 == 1);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			prebw[i][j] = prebw[i - 1][j] + prebw[i][j - 1] - prebw[i-1][j-1] + (b[i][j] != bw[i][j]);
			prewb[i][j] = prewb[i - 1][j] + prewb[i][j - 1] - prewb[i-1][j-1] + (b[i][j] != wb[i][j]);
		}
	}

	int ans = INF;
	for (int i = 0; i <= n - k; i++)
	{
		for (int j = 0; j <= m - k; j++)
		{
			int casebw = prebw[i + k][j + k] - prebw[i][j + k] - prebw[i + k][j] + prebw[i][j];
			int casewb = prewb[i + k][j + k] - prewb[i][j + k] - prewb[i + k][j] + prewb[i][j];
			ans = min({ ans, casebw, casewb });
		}
	}

	cout << ans;

	return 0;
}
