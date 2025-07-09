#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;

ll func(ll x)
{
	ll res = 0;
	for (ll i = 2; i / 2 <= x; i*=2)
	{
		res += x / i * (i / 2);
		if (x % i > i / 2)
		{
			res += x % i - (i / 2);
		}
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b;
	cin >> a >> b;
	cout << func(b+1) - func(a);

	return 0;
}