#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int v[500005];
int up[500005];
int dp[500005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	up[0] = 1;
	dp[0] = 1;
	for (int i = 1; i < n; i++)
	{
		if (v[i - 1] <= v[i]) // 오르막 또는 같은 높이면
		{
			up[i] = up[i - 1] + 1; // 오르막 길이 갱신
			
		}
		else // 내리막이면
		{
			up[i] = 1; // 지금까지의 오르막 길이 초기화
		}

		if (v[i - 1] < v[i]) // 오르막이면
		{
			dp[i] = up[i];
		}
		else // 내리막 또는 같은 높이면
		{
			dp[i] = dp[i - 1] + 1;
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += dp[i];
	}

	cout << ans;
	

	return 0;
}