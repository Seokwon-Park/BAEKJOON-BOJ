#include <bits/stdc++.h>

using namespace std;

int a;
int dp[50];

int fibonacci(int n) {

	dp[1] = dp[2] = 1;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		a++;
	}
	return dp[n];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	fibonacci(n);

	cout << dp[n] << ' ' << a;

	return 0;
}