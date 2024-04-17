#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int dp[2005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	fill(dp, dp + n, 1);

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[j] > v[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	cout << n - *max_element(dp, dp + n);

	return 0;
}