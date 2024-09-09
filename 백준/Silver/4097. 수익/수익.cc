
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	while (1)
	{
		int n;
		cin >> n;
		if (n == 0) break;
		vector<ll> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		vector<ll> dp(n);
		dp[0] = v[0];
		for (int i = 1; i < n; i++)
		{
			dp[i] = max(dp[i - 1] + v[i], v[i]);
		}

		cout << *max_element(dp.begin(), dp.end()) << '\n';

	}
	return 0;
}
