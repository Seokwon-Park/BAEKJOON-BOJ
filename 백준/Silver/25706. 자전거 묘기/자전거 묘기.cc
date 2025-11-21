#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int n;
int v[200005];
int dp[200005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = n-1; i >=0; i--)
	{
		cin >> v[i];
	}

	dp[0] = 1;
	for (int i = 1; i < n; i++)
	{
		int cnt = 1;
		if (i - v[i] - 1 < 0)
		{
			dp[i] = cnt;
		}
		else
		{
			dp[i] = cnt + dp[i - v[i] - 1];
		}
	}

	for (int i = n - 1; i >= 0; i--)
	{
		cout << dp[i] << ' ';
	}

	return 0;
}