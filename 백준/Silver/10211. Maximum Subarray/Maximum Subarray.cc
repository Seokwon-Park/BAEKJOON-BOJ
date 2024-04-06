#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int dp[1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		for (int& i : v)
		{
			cin >> i;
		}

		dp[0] = v[0];
		for (int i = 1; i < n; i++)
		{
			dp[i] = max(dp[i - 1] + v[i], v[i]);
		}
		cout << *max_element(dp, dp + n) << '\n';

	}
	return 0;
}
