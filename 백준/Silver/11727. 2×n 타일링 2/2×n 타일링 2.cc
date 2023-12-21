#include <bits/stdc++.h>

using namespace std;

int dp[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 3;
	dp[3] = 5;

	for (int i = 4; i <= n; i++)
	{
		dp[i] = (dp[i - 1] % 10007 + dp[i - 2]*2 %10007) %10007;
	}

	cout << dp[n];

	return 0;
}