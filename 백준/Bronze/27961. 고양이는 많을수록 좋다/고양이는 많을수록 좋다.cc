#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;

	if (n == 0)
	{
		cout << 0;
		return 0;
	}

	ll ans = 1;
	ll st = 1;
	while (st != n)
	{
		if (n - st >= st)
			st *= 2LL;
		else
			st += n - st;
		ans++;
	}

	cout << ans;

	return 0;
}
