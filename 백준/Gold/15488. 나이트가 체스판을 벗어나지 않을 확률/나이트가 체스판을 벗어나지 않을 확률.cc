#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

double dp[55][55][55]; // r, c, k
// x, y 좌표에 k 번이동한 후에 도착할 확률
int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
int dy[8] = { -1,-2,-2,-1,1,2,2,1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x, y, k;
	cin >> n >> x >> y >> k;

	dp[x][y][0] = 1.0;

	for (int i = 1; i <= k; i++)
	{
		for (int r = 1; r <= n; r++)
		{
			for (int c = 1; c <= n; c++)
			{
				if (dp[r][c][i - 1] > 0.0)
				{
					for (int j = 0; j < 8; j++)
					{
						int tx = r + dx[j];
						int ty = c + dy[j];
						if (tx <1 || ty <1 || tx >n || ty >n) continue;
						dp[tx][ty][i] += dp[r][c][i - 1] / 8.0;
					}
				}
			}
		}
	}

	double ans = 0.0;
	for (int r = 1; r <= n; r++)
	{
		for (int c = 1; c <= n; c++)
		{
			ans += dp[r][c][k];
		}
	}

	cout << fixed << setprecision(9) << ans;

	return 0;
}