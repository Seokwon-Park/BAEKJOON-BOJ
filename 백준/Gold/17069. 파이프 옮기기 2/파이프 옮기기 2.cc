#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int b[35][35];

ll dp[35][35][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> b[i][j];
		}
	}

	dp[1][2][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (b[i][j] == 1) continue;
			if (i == 1 && j == 2) continue;
			dp[i][j][0] = dp[i][j - 1][1] + dp[i][j - 1][0];
			if(b[i-1][j] != 1 && b[i][j-1] != 1)
				dp[i][j][1] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
			dp[i][j][2] = dp[i - 1][j][1] + dp[i - 1][j][2];
		}
	}

	cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];

	return 0;
}