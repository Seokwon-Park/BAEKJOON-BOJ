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
	
	ll w, h, k, t;
	cin >> w >> h >> k >> t;

	ll ans = 1;
	for (int i = 0; i < k; i++)
	{
		ll x, y;
		cin >> x >> y;
		ll minx = max(1LL, x - t);
		ll miny = max(1LL, y - t);
		ll maxx = min(w, x + t);
		ll maxy = min(h, y + t);
		ll width = maxx - minx + 1;
		ll height = maxy - miny + 1;

		ans *= (width * height) % 998244353LL;;
		ans %= 998244353LL;
	}

	cout << ans;


	return 0;
}