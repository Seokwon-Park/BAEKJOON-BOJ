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

	ll num;
	cin >> num;

	ll n = num;

	ll ans = 0;
	ans += n / 5;
	n %= 5;
	while (n % 3 != 0)
	{
		n += 5;
		if (n > num)
		{
			cout << -1;
			return 0;
		}
		ans--;
	}
	cout << ans + n / 3;




	return 0;
}