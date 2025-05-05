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

	ll n;
	cin >> n;
	ll ans = LLONG_MAX;
	for (int i = 0; i < n; i++)
	{
		ll m, o;
		cin >> m >> o;
		if (o == 0)
		{
			ans = min(ans, m);
		}
	}
	if (ans == LLONG_MAX) cout << -1;
	else cout << ans;
	
	return 0;
}