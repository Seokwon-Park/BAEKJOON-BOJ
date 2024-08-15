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

	ll n, m;
	cin >> n >> m;

	ll ans = 0;
	
	if (n == 1 || n == 5)
		ans = m * 8;
	else
		ans = m * 4;

	bool isRev = (ans/4)%2;

	/*while (m > 0)
	{
		if (n == 1)
		{
			if (!isRev)
				m--;
		}
		else if (n == 5)
		{
			if (isRev)
				m--;
		}
		else
			m--;
		ans += 4LL;
		isRev = !isRev;
	}*/

	if (isRev)
	{
		ans += 5LL - n;
	}
	else if (!isRev)
	{
		ans += n - 1LL;
	}
	cout << ans;


	return 0;
}