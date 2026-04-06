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

ll t, n, a, b, k;

bool solve(ll x)
{
	ll an = (n + 1) / 2;
	ll bn = n / 2;
	ll aa = min(a, x);
	ll bb = min(b, x);
	ll total = an * aa + bb * bn;

	return k * x <= total;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> t >> n >> a >> b >> k;

	int st = 0;
	int en = t + 1;
	while (st + 1 < en)
	{
		int mid = (st + en) / 2;
		if (solve(mid))
		{
			st = mid;
		}
		else
		{
			en = mid;
		}
	}
	cout << st;

	return 0;
}