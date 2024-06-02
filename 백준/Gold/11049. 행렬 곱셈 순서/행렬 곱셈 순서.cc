#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int dp[505][505];
pii v[505];

int func(int l, int r)
{
	if (dp[l][r] != INF) return dp[l][r];
	if (l == r)
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < r-l; i++)
		{
			dp[l][r] = min(dp[l][r], func(l, l+i) + func(l+i+1, r) + v[l].first * v[l+i].second * v[r].second);
		}
	}
	return dp[l][r];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int st, en;
		cin >> st >> en;
		v[i] = { st,en };
		fill(dp[i], dp[i] + n, INF);
	}

	cout << func(0, n - 1);

	return 0;
}