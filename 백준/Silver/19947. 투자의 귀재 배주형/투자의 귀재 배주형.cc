#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int dp[11];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int h, y;
	cin >> h >> y;

	dp[0] = h;
	for (int i = 1; i <= y; i++)
	{
		if (i >= 1)
		{
			dp[i] = max(dp[i], dp[i - 1] + dp[i - 1] * 5 / 100);
		}
		if (i >= 3)
		{
			dp[i] = max(dp[i], dp[i - 3] + dp[i - 3] / 5);
		}
		if (i >= 5)
		{
			dp[i] = max(dp[i], dp[i - 5] + dp[i - 5] * 35 / 100);
		}
	}
	cout << dp[y];


	return 0;
}