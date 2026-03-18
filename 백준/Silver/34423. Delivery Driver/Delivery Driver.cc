#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int cost[3];
int v[105][3];
int dp[105][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 3; i++)
	{
		cin >> cost[i];
	}

	int n;
	cin >> n;

	for (int j = 0; j < 3; j++)
	{
		{
			for (int i = 1; i <= n; i++)
				cin >> v[i][j];
		}
	}

	dp[1][0] = v[1][0];
	dp[1][1] = v[1][1];
	dp[1][2] = v[1][2];
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = max({ dp[i - 1][0], dp[i - 1][1] - cost[0], dp[i - 1][2] - cost[1] }) + v[i][0];
		dp[i][1] = max({ dp[i - 1][0] - cost[0], dp[i - 1][1], dp[i - 1][2] - cost[2] }) + v[i][1];
		dp[i][2] = max({ dp[i - 1][0] - cost[1], dp[i - 1][1] - cost[2], dp[i - 1][2] }) + v[i][2];
	}

	cout << *max_element(dp[n], dp[n] + 3);

	return 0;
}