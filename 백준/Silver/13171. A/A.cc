#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

ll fast_pow(ll a, ll x)
{
	if (x == 0)
		return 1;
	ll res = fast_pow(a, x / 2);
	if (x % 2)
		return ((res * res)%MOD*a)%MOD;
	else
		return (res * res)%MOD;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, x;
	cin >> a >> x;

	cout << fast_pow(a%MOD, x);

	return 0;
}