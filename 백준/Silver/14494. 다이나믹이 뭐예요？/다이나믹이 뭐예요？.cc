#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

ll dp[1005][1005];
const int mod = 1e9+7;

ll topdown(int n, int m)
{
	if (n == 0 || m == 0) return 0;
	if (dp[n][m])
		return dp[n][m];
	return dp[n][m] = (topdown(n-1, m)%mod + topdown(n,m-1)%mod+ topdown(n-1,m-1)%mod)%mod;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	
	dp[1][1] = 1;

	cout << topdown(n, m);
	

	return 0;
}
