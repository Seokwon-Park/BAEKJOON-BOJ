#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dp1[1005];
int dp2[1005];

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

	fill(dp1, dp1 + n, 1);
	fill(dp2, dp2 + n, 1);

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[i] < v[j])
			{
				dp1[i] = max(dp1[i], dp1[j] + 1);
			}
		}
	}

	for (int i = n-2; i >=0 ; i--)
	{
		for (int j = n-1; j > i; j--)
		{
			if (v[i] < v[j])
			{
				dp2[i] = max(dp2[i], dp2[j] + 1);
			}
		}
	}

	if (n == 1)
	{
		cout << 1;
		return 0;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans = max(ans, dp1[i] + dp2[i]-1);
	}
	cout << ans;

	return 0;
}