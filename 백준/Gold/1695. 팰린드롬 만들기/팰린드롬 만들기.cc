#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int dp[5005][5005];
int v[5005];

int func(int s, int e)
{
	if (s >= e) return 0;
	if (dp[s][e] != -1)
	{
		return dp[s][e];
	}
	if (v[s] == v[e])
	{
		dp[s][e] = func(s + 1, e - 1);
	}
	else
	{
		dp[s][e] = min(func(s + 1, e), func(s, e - 1))+1;
	}
	return dp[s][e];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		fill(dp[i], dp[i] + n, -1);
		cin >> v[i];
	}

	cout << func(0, n - 1);

	return 0;
}