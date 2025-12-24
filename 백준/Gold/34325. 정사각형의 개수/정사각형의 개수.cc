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

ll v[1000005];


ll fast(ll x, ll exp)
{
	ll n = x;
	ll ret = 1;
	while (exp)
	{
		if (exp % 2)
		{
			ret *= n;
			ret %= MOD;
		}
		n *= n;
		n %= MOD;
		exp /= 2;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, k;
	cin >> n >> k;
	 
	v[1] = 1;
	v[2] = 4;

	//a0 = 1 a0+2(n-1) = i-2 = 1;
	//
	for (ll i = 3; i <= n; i++)
	{
		ll a0 = 0;
		if (i % 2) a0 = 1;
		else a0 = 2;
		ll m = (i - 2 - a0) / 2 + 1;
		ll tri = (2 * a0 + 2 * (m - 1)) * m / 2;
		v[i] = (i * i + tri * 4) % MOD;
	}

	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		ans += v[n - i] * fast(k, i + 1);
		ans %= MOD;
	}

	cout << ans;

	//ll ans = ai * fast(k, ntmp);
	//ans %= MOD;
	//cout << ans;



	return 0;
}
