#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

ull dp[116];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i < n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 3];
	}

	cout << dp[n-1];

	return 0;
}