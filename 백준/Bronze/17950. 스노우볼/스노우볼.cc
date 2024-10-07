#include<bits/stdc++.h>

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

	ll h, x;
	cin >> h >> x;
	ll st = 1;
	ll ans = 0;
	for (int i = 0; i < h; i++)
	{
		ll n;
		cin >> n;
		st = (st * x) % MOD;
		ans += (n * st)%MOD;
		ans %= MOD;
	}
	cout << ans;

	return 0;
}