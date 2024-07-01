#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

ll fast_pow(ll c, ll n)
{
	if (n == 1)
		return c;
	ll res = fast_pow(c, n / 2);
	ll ret = 0;
	if (n % 2 == 0)
	{
		ret = res * res;
	}
	else
	{
		ret = ((res * res)%MOD) * c;
	}
	return ret % MOD;
}

ll gcd(ll a, ll b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ll ni, si;
		cin >> ni >> si;
		
		ll g = gcd(ni, si);
		ll a = si / g;
		ll b = ni / g;

		b = fast_pow(b, MOD - 2);
		ans += (a * b) % MOD;
		ans %= MOD;
	}
	cout << ans;

	return 0; 
}