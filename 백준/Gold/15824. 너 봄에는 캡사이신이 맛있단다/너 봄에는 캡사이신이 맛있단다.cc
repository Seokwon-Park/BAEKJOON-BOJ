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

ll power(ll x, int exp)
{
	ll ret = 1;
	while (exp)
	{
		if (exp % 2)
		{
			ret = ret * x % MOD;
		}
		exp /= 2;
		x = x * x % MOD;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<ll> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ll mx = power(2, i);
		ll mn = power(2, n - i - 1);
		ans += v[i] * ((mx - mn + MOD) % MOD);
		ans %= MOD;
	}
	cout << ans;

	return 0;
}