#include <bits/stdc++.h>

using namespace std;

int stair[301];
int dp[301];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	int total = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> stair[i];
		total += stair[i];
	}

	if (n <= 2)
	{
		cout << total;
		return 0;
	}

	dp[1] = stair[1];
	dp[2] = stair[2];
	dp[3] = stair[3];

	for (int i = 4; i <= n-1; i++)
	{
		dp[i] = min(dp[i - 2], dp[i - 3]) + stair[i];
	}

	cout << total - min(dp[n-1],dp[n-2]);

	return 0;
}
