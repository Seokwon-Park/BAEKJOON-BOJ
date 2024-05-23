#include <bits/stdc++.h>

#define INF 0x3f3f3f
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;

int dp[205];

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
		dp[i] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[i] > v[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int mx = *max_element(dp, dp + n);
	cout << n - mx;


	return 0;
}