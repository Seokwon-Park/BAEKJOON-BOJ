
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
	n = abs(n);
	ll ans = 0;
	if (n % 2 == 0)
	{
		if (n == 0)
		{
			cout << 0;
		}
		else
		{
			cout << -1;
		}
		return 0;
	}
	while (n)
	{
		n /= 2;
		ans++;
	}
	cout << ans;

	return 0;
}
