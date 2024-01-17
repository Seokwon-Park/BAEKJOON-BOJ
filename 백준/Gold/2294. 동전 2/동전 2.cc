#include <bits/stdc++.h>

using namespace std;

int dp[100005];


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;

	fill(dp, dp + k + 1, 0x3f3f3f3f);

	vector<int> coin;
	for (int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		coin.push_back(c);
		dp[c] = 1;
	}

	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i - coin[j] <= 0 )continue; // 0보다 작은 인덱스거나 0인경우( 두 값이 같은 경우) dp를 구하지 않는다.
			dp[i] = min(dp[i], dp[i - coin[j]] + dp[coin[j]]);
		}
	}

	if (dp[k] == 0x3f3f3f3f)
		cout << -1;
	else
		cout << dp[k];

	return 0;
}