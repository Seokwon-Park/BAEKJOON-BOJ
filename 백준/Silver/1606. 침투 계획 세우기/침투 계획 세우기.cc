#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll x, y;
	cin >> x >> y;

	ll a = max(1LL, y)*6; // d = 6;
	ll ans = 1LL + y + (y * (y - 1) / 2LL) *6+ a * x + 6 * x * (x - 1) / 2;

	cout << ans;
	
	return 0;
} 