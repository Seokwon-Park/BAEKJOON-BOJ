#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;

ll dp[81];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	dp[0] = 1;
	dp[1] = 1;

	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	ll res = (dp[n] + dp[n - 1]) * 2;
	cout << res;

	return 0;
}