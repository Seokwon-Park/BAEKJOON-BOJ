#include <bits/stdc++.h>

using namespace std;

int dp[105][100005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> wv;

	wv.push_back({ 0 ,0});
	
	for (int i = 0; i < n; i++)
	{
		int w, v;
		cin >> w >> v;
		wv.push_back({ w,v });
	}

	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (wv[j].first <= i)
			{
				dp[j][i] = max(dp[j-1][i], dp[j-1][i-wv[j].first] + wv[j].second);
			}
			else
			{
				dp[j][i] = dp[j-1][i];
			}
		}
	}

	cout << dp[n][k];
	
 	return 0;
}


