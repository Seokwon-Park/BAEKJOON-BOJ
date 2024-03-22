#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll dp[46];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= 45; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}

	return 0;
}
