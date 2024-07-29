
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int dp[105][55];
int sum[105];

int func(int n, int m) {
	if (m == 0)
		return 0;
	if (n < 0)
		return -INF/2;
	if (dp[n][m] != -INF)
		return dp[n][m];
	dp[n][m] = func(n - 1, m);
	for (int i = n; i > 0; i--)
	{
		int tmp = func(i - 2, m - 1) + sum[n] - sum[i - 1];
		// dp => (4,2) (3,2) (2,2) (1,2) (0,2) + 6 / 5~6 / 4~6/ 3~6/ 2~6/ 1~6
		dp[n][m] = max(tmp, dp[n][m]);
	}
	return dp[n][m];
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		fill(dp[i], dp[i] + 55, -INF);

	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		sum[i] = sum[i - 1] + k;
	}

	cout << func(n, m);

	return 0;
}