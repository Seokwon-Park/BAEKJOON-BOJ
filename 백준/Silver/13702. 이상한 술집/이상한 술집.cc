#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int n, k;
ll v[10005];

int solve(ll mid)
{
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		res += v[i] / mid;
	}
	return res >= k;
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

	ll st = 0;
	ll en = INT_MAX - 1;

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

	cout << st;

	return 0;
}
