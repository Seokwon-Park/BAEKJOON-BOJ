#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
//const int MOD = 1'000'000'007;
const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int l, n, m;
	cin >> l >> n >> m;
	vector<int> a(l), b(n), c(m);
	for (int& i : a) cin >> i;
	for (int& i : b) cin >> i;
	for (int& i : c) cin >> i;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());

	int ans = INF;
	for (int ai : a)
	{
		int bi;
		int bix = lower_bound(b.begin(), b.end(), ai) - b.begin();
		if (b[bix] == ai)
		{
			bi = ai;
			for (int ci : c)
			{
				ans = min(ans, max({ ai,bi,ci }) - min({ ai,bi,ci }));
			}

		}
		else
		{
			int lower = max(0, bix - 1);
			int upper = min(bix, n);

			for (int ci : c)
			{
				ans = min(ans, max({ ai,b[lower],ci}) - min({ai,b[lower],ci}));
			}
			for (int ci : c)
			{
				ans = min(ans, max({ ai,b[upper],ci}) - min({ai,b[upper],ci}));
			}
		}
	}
	cout << ans;

	return 0;
}
