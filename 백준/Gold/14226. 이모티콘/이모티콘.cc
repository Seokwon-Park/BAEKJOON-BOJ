#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;

int dp[3005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	fill(dp, dp + 1005, 0x3f3f3f);
	int s;
	cin >> s;
	dp[1] = 0;

	for (int i = 1; i <= s+1; i++)
	{
		dp[i * 2] = min(dp[i * 2], dp[i] + 2);
		dp[i * 2 - 1] = min(dp[i * 2 - 1], dp[i * 2] + 1);

		for (int j = i * 3; j <= s * 2; j += i)
		{
			dp[j] = min(dp[j], dp[i] + j/i);
			dp[j - 1] = min(dp[j - 1], dp[j] + 1);
		}
	}

	cout << dp[s];

	return 0;
}