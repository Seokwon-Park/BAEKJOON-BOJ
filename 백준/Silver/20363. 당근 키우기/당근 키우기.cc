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

	ll x, y;
	cin >> x >> y;
	if (x < y)
		swap(x, y);

	ll ans = 0;
	ans = x;
	ans += y / 10;
	ans += y;
	cout << ans;

	return 0;
}