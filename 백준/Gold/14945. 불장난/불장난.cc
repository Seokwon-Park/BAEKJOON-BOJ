#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

//굉장히 독특한 풀이, dp[층수][두사람간의 거리]
int dp[105][105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	dp[2][1] = 1;

	//dp[3][1] = 2;
	//dp[3][2] = 1;

	//dp[4][1] = 5;
	//dp[4][2] = 4;
	//dp[4][3] = 1;

	for (int i = 3; i <= n; i++)
	{
		for (int j = 1; j <= n-1; j++)
		{
			dp[i][j] = dp[i - 1][j] * 2;
			dp[i][j] %= 10007;
			if (j - 1 > 0)
			{
				dp[i][j] += dp[i - 1][j - 1];
				dp[i][j] %= 10007;
			}
			if (j + 1 <= n - 1)
			{
				dp[i][j] += dp[i - 1][j + 1];
				dp[i][j] %= 10007;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n - 1; i++)
	{
		ans += dp[n][i];
		ans %= 10007;
	}
	cout << (ans * 2)% 10007;

	return 0;
}
