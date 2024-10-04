#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

ll dp[200005][4];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> v(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	dp[1][0] = v[1];
	dp[1][3] = v[1] * 2;

	dp[2][0] = v[1] + v[2];
	dp[2][2] = dp[1][3] + v[2] * 2;
	dp[2][3] = v[1] + v[2] * 2;

	dp[3][0] = dp[2][0] + v[3];
	dp[3][1] = dp[2][2] + v[3] * 2;
	dp[3][2] = dp[2][3] + v[3] * 2;
	dp[3][3] = dp[2][0] + v[3] * 2;

	for (int i = 4; i <= n; i++)
	{
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + v[i];
		dp[i][1] = (dp[i - 1][2]) + v[i] * 2;
		dp[i][2] = (dp[i - 1][3]) + v[i] * 2;
		dp[i][3] = max(dp[i - 1][0], dp[i - 1][1]) + v[i] * 2;
	}

	cout << *max_element(dp[n], dp[n] + 4);
	return 0;
}

