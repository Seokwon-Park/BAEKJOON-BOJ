#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

ll v[1000005];
int n, k;

bool solve(ll mid)
{
	ll res = 0;
	for (int i = 0; i < n; i++)
	{
		if (res >= 1e18)
			return false;
		res += max(0LL, mid - v[i]);
	}
	return res <= k;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	ll st = 1;
	ll en = 1e15;
	while (st < en)
	{
		ll mid = (st + en+1) / 2LL; 
		if (solve(mid))
		{
			st = mid;
		}
		else
		{
			en = mid-1;
		}
	}
	cout << st;

	return 0;
}
