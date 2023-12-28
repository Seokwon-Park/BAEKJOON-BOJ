#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005]; //dp[i][j] a에서 i번째 b에서 j번째까지 탐색했을때 일치하는 최대 길이

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	cin >> a >> b;

	int m = a.length();
	int n = b.length();

	for (int i = 0; i < m; i++) // A is y axis
	{
		dp[i][0] = 0;
	}

	for (int i = 0; i < n; i++) // B is x axis
	{
		dp[0][i] = 0;
	}
	//https://en.wikipedia.org/wiki/Longest_common_subsequence	
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[i-1] == b[j-1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout <<	dp[m][n];


	return 0;
}
