#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

ll dp[1000005];

ll func(ll n)
{
	if (n == 1) return 0;
	if (n <= 1000000)
	{
		if (dp[n] != -1)
			return dp[n];
		else
			return dp[n] = func(n / 2) + func(n - n / 2) + n / 2 * (n - n / 2);
	}
	return func(n / 2) + func(n - n / 2) + n/2*(n-n/2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	fill(dp, dp + 1000005, -1);

	cout << func(n);

	return 0;
}