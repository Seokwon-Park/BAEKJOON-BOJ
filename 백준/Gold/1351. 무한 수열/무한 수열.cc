#include <bits/stdc++.h>

using namespace std;

long long n, p, q;
unordered_map<long long, long long> dp;

long long func(long long i)
{
	if (dp[i] != 0)
		return dp[i];
	return dp[i] = func(i/p) + func(i/q);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> p >> q;
	dp[0] = 1;

	cout << func(n);

	return 0;
}
