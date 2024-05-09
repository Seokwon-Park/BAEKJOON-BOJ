#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

ll dp[31][31];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	dp[1][0] = 1;
	dp[1][1] = 1;

	while (1)
	{
		int n;
		cin >> n;
		if (!n) break;
		for (int i = 2; i <= n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if (j == 0)
				{
					dp[i][j] = dp[i - 1][j];
				}
				else
				{
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}
		}
		cout << dp[n][n] << '\n';
	}

	return 0;
}
