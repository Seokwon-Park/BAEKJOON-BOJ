#include <bits/stdc++.h>

using namespace std;

int dp[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> arr(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = max(dp[i-1] + arr[i], arr[i]);
	}

	cout << *max_element(dp+1, dp+n+1);
	

	return 0;
}