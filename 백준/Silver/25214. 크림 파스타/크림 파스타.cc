#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int dp[200005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> v(n+1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	int mn = INF;
	for (int i = 1; i <= n; i++)
	{
		mn = min(mn, v[i]);
		dp[i] = max(dp[i - 1], v[i] - mn);

	}
	for (int i = 1; i <= n; i++)
	{
		cout << dp[i] << ' ';
	}

	return 0;
}