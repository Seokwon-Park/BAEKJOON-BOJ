#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

ll n, k;

bool solve(ll mid)
{
	ll res = 0;
	for (int i = 1; i <= n; i++)
	{
		res += min(n, mid / i);
	}
	return res >= k;

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> k;

	ll st = 1;
	ll en = n * n;
	ll ans = 0;

	while (st < en)
	{
		ll mid = (st + en) / 2;
		if (solve(mid))
		{
			en = mid;
		}
		else
		{
			st = mid + 1;
		}
	}
	cout << st;

	return 0;
}