#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int dp[25][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n;
	vector<int> small(n + 1);
	vector<int> big(n + 1);

	for (int i = 1; i <= n - 1; i++)
	{
		cin >> small[i] >> big[i];
	}

	cin >> k;


	fill(dp[0], dp[0] + 25, INF);
	fill(dp[1], dp[1] + 25, INF);
	dp[1][0] = 0;
	dp[2][0] = small[1];
	dp[3][0] = min(small[1] + small[2], big[1]);
	for (int i = 4; i <= n; i++)
	{
		dp[i][0] = min(dp[i - 1][0] + small[i - 1], dp[i - 2][0] + big[i - 2]);
		dp[i][1] = min({ dp[i - 1][1] + small[i - 1], dp[i - 2][1] + big[i - 2], dp[i - 3][0] + k });
	}

	cout << min(dp[n][0], dp[n][1]);

	return 0;
}

