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

ll pow(int x, int exp)
{
	ll n = x;
	ll ret = 1;
	while (exp)
	{
		if (exp % 2)
		{
			ret *= n;
		}
		n *= n;
		exp /= 2;
	}
	return ret;
}

ll intlen(ll x)
{
	return to_string(x).size();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		ll cur = a;
		
		while (1)
		{
			ll len = intlen(cur);
			ll bound = pow(10, len) - 1;
			ll count = (bound - cur) / b + 1;

			ll total = len * count;
			if (total < c)
			{
				c -= total;
				cur += count * b;
			}
			else
			{
				ll order = (c - 1) / len;
				ll n = cur + order * b;
				ll idx = (c - 1) % len;
				cout << to_string(n)[idx] << '\n';
				break;
			}
		}
	}
	

	return 0;
}
