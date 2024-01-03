#include <bits/stdc++.h>

using namespace std;

int dp[50005];
// dp[i]: i를 만드는데 필요한 최소 개수의 제곱수
// dp[1] = 1, dp[2] = min(dp[2], dp[1] + dp[2-1])
// dp[3] = min(dp[3], dp[1] + dp[3-1])....

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	fill(dp, dp + n + 5, 0x3f3f3f3f);

	for (int i = 1; i * i <= n; i++)
	{
		dp[i * i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j*j <= i; j++)
		{
			dp[i] = min(dp[i], dp[j*j] + dp[i - j*j]);
		}
	}

	cout << dp[n];

	return 0;
}