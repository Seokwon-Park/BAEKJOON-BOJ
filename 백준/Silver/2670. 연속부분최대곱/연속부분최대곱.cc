#include <bits/stdc++.h>

using namespace std;

using ll = long long;

double dp[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<double> v(n);
	for (auto& d : v)
		cin >> d;
	dp[0] = v[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = max(dp[i - 1] * v[i], v[i]);
	}

	cout << fixed;
	cout.precision(3);
	cout << *max_element(dp, dp + n);

	return 0;
}