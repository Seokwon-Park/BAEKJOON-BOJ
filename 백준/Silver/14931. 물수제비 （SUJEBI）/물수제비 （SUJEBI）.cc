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

	int l;
	cin >> l;
	vector<int> v(l);
	for (int i = 0; i < l; i++)
	{
		cin >> v[i];
	}

	ll ans = 0;
	ll ansgap = 0;
	for (int gap = 1; gap <= l; gap++)
	{
		ll res = 0;
		for (int j = gap-1; j < l; j += gap)
		{
			res += v[j];
		}
		if (res > ans)
		{
			ans = res;
			ansgap = gap;
		}
	}

	cout << ansgap << ' ' << ans;



	return 0;
}


