#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int dp[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	fill(dp, dp + 1005, 1);

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	cout << *max_element(dp, dp + n);

	return 0;
}