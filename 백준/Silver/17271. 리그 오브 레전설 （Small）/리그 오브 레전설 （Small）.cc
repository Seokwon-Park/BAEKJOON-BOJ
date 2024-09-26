#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int dp[10005][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		dp[i][0] = 1;
	}
	dp[m][1] = 1; // B
	for (int i = m + 1; i <= n; i++)
	{
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1])%MOD;
		dp[i][1] = (dp[i - m][0] + dp[i - m][1])%MOD;
	}

	cout << (dp[n][0] + dp[n][1])%MOD;




	return 0;
}

