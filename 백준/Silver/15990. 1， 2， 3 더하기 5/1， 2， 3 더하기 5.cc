#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

ll dp[100005][4];
const int mod = 1e9 + 9;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	dp[1][1] = 1;
	dp[1][2] = 0;
	dp[1][3] = 0;
	dp[2][1] = 0;
	dp[2][2] = 1;
	dp[2][3] = 0;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;


	for (int i = 4; i <= 100000; i++)
	{
		dp[i][1] = dp[i - 1][2] % mod + dp[i - 1][3] % mod;
		dp[i][1] %= mod;
		dp[i][2] = dp[i - 2][1] % mod + dp[i - 2][3] % mod;
		dp[i][2] %= mod;
		dp[i][3] = dp[i - 3][1] % mod + dp[i - 3][2] % mod;
		dp[i][3] %= mod;
	}

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		cout << (dp[n][1] + dp[n][2] + dp[n][3])%mod << '\n';;
	}



	return 0;
}
