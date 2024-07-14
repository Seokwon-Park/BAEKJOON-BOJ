#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

vector<int> dots[100005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pii> v;
	for (int i = 1; i <= n; i++)
	{
		int x, color;
		cin >> x >> color;
		dots[color].push_back(x);
		v.push_back({ x, color });
	}

	for (int i = 1; i <= n; i++)
	{
		if (!dots[i].empty())
			sort(dots[i].begin(), dots[i].end());
	}

	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		auto [x, y] = v[i];
		int ix = lower_bound(dots[y].begin(), dots[y].end(), x) - dots[y].begin();
		ll l = INT_MAX;
		ll r = INT_MAX;
		if (ix > 0)
		{
			l = abs(x - dots[y][ix - 1]);
		}
		if (ix < dots[y].size() - 1)
		{
			r = abs(x - dots[y][ix + 1]);
		}
		if (l != INT_MAX || r != INT_MAX)
			ans += min(l, r);
	}
	cout << ans;

	return 0;
}