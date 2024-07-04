#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int dp[6][6][3];
int b[6][6];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
			fill(dp[i][j], dp[i][j] + 3, INF);
		}
	}

	for (int j = 0; j < m; j++)
	{
		dp[0][j][0] = b[0][j];
		dp[0][j][1] = b[0][j];
		dp[0][j][2] = b[0][j];
	}


	// / | \ 차례대로 dir 0,1,2라고 가정한다.
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j > 0) // 이 경우는 왼쪽 위에서 가져오는 거
			{
				dp[i][j][2] = min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][0]) + b[i][j];
			}
			dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + b[i][j];
			if (j < m - 1)
			{
				dp[i][j][0] = min(dp[i - 1][j + 1][1], dp[i - 1][j + 1][2]) + b[i][j];

			}
		}
	}

	int ans = INF;
	for (int j = 0; j < m; j++)
	{
		ans = min(*min_element(dp[n - 1][j], dp[n - 1][j] + 3), ans);
	}

	cout << ans;

	return 0;
}
