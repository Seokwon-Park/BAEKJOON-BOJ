#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<pii> v(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[i] = { x,y };
	}

	ll cmp = LLONG_MAX;
	pii ans;
	for (int a = 1; a <= 100; a++)
	{
		for (int b = 1; b <= 100; b++)
		{
			ll res = 0;
			for (int i = 0; i < n; i++)
			{
				auto [x, y] = v[i];
				ll tmp = y - (a * x + b);
				res += tmp * tmp;
			}
			if (res < cmp)
			{
				ans = { a,b };
				cmp = res;
			}
		}
	}
	cout << ans.first << ' ' << ans.second;


	return 0;
}