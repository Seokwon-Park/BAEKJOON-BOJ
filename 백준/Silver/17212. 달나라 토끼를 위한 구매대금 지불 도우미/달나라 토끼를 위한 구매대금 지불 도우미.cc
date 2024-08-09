#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int dp[100005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vector<int> coins = { 1,2,5,7 };
	fill(dp, dp + 100005, INF);
	dp[0] = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i - coins[j] < 0) continue;
			dp[i] = min(dp[i], dp[i - coins[j]] + 1);
		}
	}
	cout << dp[n];
	

	return 0;
}