#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int dp[21][105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> v(n+1);
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		v[i].first = a;
	}
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		v[i].second= a;
	}
	sort(v.begin(), v.end());
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			if (v[i].first < j)
				dp[i][j] = max(dp[i - 1][j], dp[i-1][j - v[i].first] + v[i].second);
			else dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n][100];
	

	return 0;
}