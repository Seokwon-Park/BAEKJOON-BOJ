#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int b[15];
int dp[15][1050];

int countbit(unsigned int n)
{
	n = (n >> 1 & 0x55555555) + (n & 0x55555555);
	n = (n >> 2 & 0x33333333) + (n & 0x33333333);
	n = (n >> 4 & 0x0F0F0F0F) + (n & 0x0F0F0F0F);
	n = (n >> 8 & 0x00FF00FF) + (n & 0x00FF00FF);
	n = (n >> 16 & 0x0000FFFF) + (n & 0x0000FFFF);
	return n;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			b[i] = 0;
			fill(dp[i], dp[i] + 1050, 0);
			for (int j = m - 1; j >= 0; j--)
			{
				char c;
				cin >> c;
				int x = (c == 'x' ? 1 : 0);
				b[i] |= x << j;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int pre = 0; pre < 1 << m; pre++)
			{
				if (pre >> 1 & pre) continue;
				for (int cur = 0; cur < 1 << m; cur++)
				{
					if (cur >> 1 & cur) continue;
					if (cur & b[i]) continue;
					if (cur & pre >> 1) continue;
					if (cur & pre << 1) continue;
					dp[i][cur] = max(dp[i][cur], dp[i - 1][pre] + countbit(cur));
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < 1 << m; i++)
		{
			ans = max(ans, dp[n][i]);
		}
		cout << ans << '\n';
	}
	return 0;
}