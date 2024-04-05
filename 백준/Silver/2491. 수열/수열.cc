#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int dp[100005];
int dp2[100005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> v(n);
	for (int& i : v)
		cin >> i;

	fill(dp, dp + n, 1);
	fill(dp2, dp2 + n, 1);

	for (int i = 1; i < n; i++)
	{
		if (v[i] >= v[i - 1])
			dp[i] = dp[i - 1] + 1;
		if (v[i] <= v[i - 1])
			dp2[i] = dp2[i - 1] + 1;

	}

	cout << max(*max_element(dp, dp + n), *max_element(dp2, dp2 + n));

	

	return 0;
}