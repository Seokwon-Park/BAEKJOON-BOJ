#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1'000'000'007;

ll dp[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	dp[0] = 0;
	dp[1] = 1;
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= MOD;
	}
	cout << dp[n];

	return 0;
}
