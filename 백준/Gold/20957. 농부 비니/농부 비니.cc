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

ll dp[10005][7][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 1; i < 10; i++)
	{
		int mod = i % 7;
		int has = i == 7;

		dp[1][mod][has]++;
	}

	for (int i = 2; i <= 10000; i++)
	{
		for (int mod = 0; mod < 7; mod++)
		{
			for (int has = 0; has < 2; has++)
			{
				for (int j = 0; j < 10; j++)
				{
					int nxtmod = (mod + j) % 7;
					int nxthas = has | (j == 7 || j == 0);
					dp[i][nxtmod][nxthas] += dp[i - 1][mod][has];
					dp[i][nxtmod][nxthas] %= MOD;
				}
			}
		}
	}


	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << dp[n][0][1] << '\n';
	}


	return 0;
}