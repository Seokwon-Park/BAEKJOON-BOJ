// 검색해서 접근방법 보고 품
#include <bits/stdc++.h>

using namespace std;

int dp[1005][10]; // i자리일 때, 마지막 수가 j이면 가질 수 있는 오르막 수의 가짓수.

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < 10; i++)
	{
		dp[1][i] = 1; // 1자리일 때 마지막 수가 i이면 1가지 경우 밖에 없다.
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[i][j] += dp[i - 1][k]; 
				//만약 dp[2][0] 을 구한다고 하면 앞에 올 수 있는 수는 dp[1][0] 밖에없다.
				//만약 dp[2][9]를 구한다고 하면 앞에 올 수 있는 수는 dp[1][0~9] 까지 올 수 있다.
				// dp[3][5]라는 값을 구하고 싶으면 dp[2][0~5]를 구하면 2자리일때 0~5로 끝나는 오르막 수를 앞에다가 붙이는 것이기 때문에 
				// 무조건 5로 끝나는 3자리 오르막수의 개수가 된다.
				dp[i][j] %= 10007;
			}
		}
	}

	int answer = 0;
	for (auto i : dp[n])
	{
		answer += i;
	}
	cout << answer%10007;

	return 0;
}