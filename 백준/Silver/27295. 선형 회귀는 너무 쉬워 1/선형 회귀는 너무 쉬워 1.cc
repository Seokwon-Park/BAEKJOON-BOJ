#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
//const int MOD = 1'000'000'007;
const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, b;
	cin >> n >> b;

	ll acoef = 0;
	ll constant = 0;

	for (int i = 0; i < n; i++)
	{
		ll x, y;
		cin >> x >> y;
		acoef += x;
		constant += b - y;
	}
	if (acoef == 0)
	{
		cout << "EZPZ";
	}
	else if (constant % acoef == 0)
	{
		cout << -constant / acoef;
	}
	else
	{
		if (acoef < 0)
		{
			acoef = -acoef;
			constant = -constant;
		}

		ll g = gcd(abs(constant), acoef);
		cout << -(constant / g) << '/' << (acoef / g);
	}

	return 0;
}