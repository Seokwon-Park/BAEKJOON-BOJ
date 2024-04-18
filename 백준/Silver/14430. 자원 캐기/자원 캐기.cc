#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int b[305][305];
int dp[305][305];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> b[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])+b[i][j];
		}
	}

	cout << dp[n][m];

	return 0;
}