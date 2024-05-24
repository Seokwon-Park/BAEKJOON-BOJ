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

	for (int i = 1; i <= s + 1; i++)
	{
		for (int j = 2; i*j <= 1005; j++)
		{
			dp[i * j] = min(dp[i * j], dp[i] + j);
			dp[i * j - 1] = min(dp[i * j - 1], dp[i * j] + 1);
		}
	}

	cout << dp[s];

	return 0;
}