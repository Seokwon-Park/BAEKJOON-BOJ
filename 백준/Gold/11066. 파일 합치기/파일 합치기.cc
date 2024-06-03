#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int dp[505][505];
int pfsum[505];
int v[505];

int func(int l, int r)
{
	if (dp[l][r] != INF) return dp[l][r];
	if (l == r)
	{
		return 0;
	}
	else
	{
		for (int i = l; i <= r ; i++)
		{
			dp[l][r] = min(dp[l][r], func(l, i) + func(i + 1, r));
		}
	}
	return dp[l][r] += pfsum[r] - pfsum[l - 1];
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			fill(dp[i]+1, dp[i] + n+1, INF);
			cin >> v[i];
			pfsum[i] = pfsum[i - 1] + v[i];
		}
		
		cout << func(1, n) << '\n';
	}

	return 0;
}