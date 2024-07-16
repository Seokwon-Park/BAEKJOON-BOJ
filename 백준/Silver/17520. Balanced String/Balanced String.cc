#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

ll dp[100005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	dp[1] = 2;
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1];
		if (i % 2)
			dp[i] = dp[i - 1] * 2 %16769023;
	}

	cout << dp[n];
	
	return 0;
}