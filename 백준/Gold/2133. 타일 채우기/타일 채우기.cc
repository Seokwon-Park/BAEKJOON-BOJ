#include <bits/stdc++.h>

using namespace std;

int dp[35];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	dp[0] = 1; // (empty)
	dp[2] = 3;
	dp[4] = 11; // dp[i-2]* dp[2] + 2(특수모형)
	//dp[6] = dp[i-2] * dp[2]의 경우 + dp[2] * (특수 모형의 개수?+ 2
	
	// 모든 짝수 길이에 대해 특별한 모형 2개씩 얻을 수 있다. n>=4인경우부터
	// 그러면 이전 길이에 대해서 특수모형 * dp[2]인 경우도 구해줘야 하고


	int n;
	cin >> n;
	for (int i = 6; i <= n; i++)
	{
		dp[i] = dp[i - 2] * dp[2];
		for (int j = i-4; j >= 0; j -= 2)
		{
			dp[i] += dp[j] * 2;
		}
	}
	
	cout << dp[n];

	return 0;
}