#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

ll v[1000005];
int s, c;


bool solve(ll mid)
{
	ll res = 0;
	for (int i = 0; i < s; i++)
	{
		res += v[i] / mid;
	}
	return res >= c;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	cin >> s >> c;

	
	for (int i = 0; i < s; i++)
	{
		cin >> v[i];
	}

	ll st = 1;
	ll en = INT_MAX - 2;
	while (st < en)
	{
		ll mid = (st + en+1) / 2;
		if (solve(mid))
		{
			st = mid;
		}
		else
		{
			en = mid-1;
		}
	}

	ll ans = 0;
	for (int i = 0; i < s; i++)
	{
		ans += v[i];
	}
	cout << ans - c * st;
	

	return 0;
}