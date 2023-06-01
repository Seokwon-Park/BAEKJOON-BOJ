#include <bits/stdc++.h>

using namespace std;

int arr[100005];
int dp[100005];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++)
	{
		dp[i] = arr[i] + dp[i - 1];
	}

	for (int k = 0; k < m; k++)
	{
		int i, j;
		cin >> i >> j;
		cout << dp[j] - dp[i-1] << '\n';

	}

	return 0;
}
