#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

ll v[1000005];
int n, m;

bool solve(ll mid)
{
	ll res = 0;
	for (int i = 0; i < n; i++)
	{
		res += mid / v[i];
	}
	return res >= m;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	ll st = 1;
	ll en = 1e15;
	while (st < en)
	{
		ll mid = (st + en) / 2;
		if (solve(mid))
		{
			en = mid;
		}
		else
		{
			st = mid +1;
		}
	}
	cout << st;

	return 0;
}