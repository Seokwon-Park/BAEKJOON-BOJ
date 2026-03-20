#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int n, k;
pii v[10005];

bool solve(int mid)
{
	int mn = INF;
	int mx = -INF;
	int res = 1;
	for (int i = 0; i < n; i++)
	{
		auto [x, y] = v[i];
		mn = min(mn, y);
		mx = max(mx, y);
		if (mx - mn > mid)
		{
			res++;
			mn = y;
			mx = y;
		}
	}
	return res <= k;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			v[i] = { x,y };
		}

		sort(v, v + n);
		int st = -1;
		int en = 200000000;
		while (st + 1 < en)
		{
			int mid = (st + en) / 2;
			if (solve(mid))
			{
				en = mid;
			}
			else
			{
				st = mid;
			}
		}
		cout << fixed << setprecision(1) << (double)en/2 << '\n';

	}



	return 0;
}