#include <bits/stdc++.h>

using namespace std;

int dp[1005];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	//dp[i] 카드i개를 갖기 위해 지불해야 하는 금액의 최댓값.
	int cards[1005];
	for (int i = 1; i <= n; i++)
	{
		cin >> cards[i];
		dp[i] = cards[i];
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i/2; j++)
		{
			dp[i] = max(dp[i], dp[j] + dp[i-j]);
		}
	}

	cout << dp[n];


	return 0;
}