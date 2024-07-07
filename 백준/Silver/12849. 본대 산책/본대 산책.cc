#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

ll dp[100005][8];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = (dp[i-1][1] + dp[i-1][2]) % MOD;
		dp[i][1] = (dp[i-1][0] + dp[i-1][2] + dp[i-1][3]) % MOD;
		dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i - 1][3] + dp[i-1][4]) % MOD;
		dp[i][3] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][4] + dp[i-1][5]) % MOD;
		dp[i][4] = (dp[i-1][2] + dp[i-1][3] + dp[i-1][5] + dp[i-1][6]) % MOD;
		dp[i][5] = (dp[i-1][3] + dp[i-1][4] + dp[i-1][7]) % MOD;
		dp[i][6] = (dp[i-1][4] + dp[i-1][7]) % MOD;
		dp[i][7] = (dp[i-1][5] + dp[i-1][6]) % MOD;
	}

	cout << dp[n][0];



	return 0;
}
