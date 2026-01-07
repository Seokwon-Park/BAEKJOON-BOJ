#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

vector<ll> segtree;

ll query(int node, int st, int en, int l, int r)
{
	if (st > r || en < l) return 0;
	if (st >= l && en <= r) return segtree[node];

	int mid = (st + en) / 2;
	return query(node * 2, st, mid, l, r) + query(node * 2 + 1, mid + 1, en, l, r);
}

void update(int node, int st, int en, int ix, ll val)
{
	if (st > ix || en < ix) return;
	segtree[node] += val;

	if (st != en)
	{
		int mid = (st + en) / 2;
		update(node * 2, st, mid, ix, val);
		update(node * 2 + 1, mid + 1, en, ix, val);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> tmp(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		tmp[i] = v[i];
	}

	sort(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

	int h = ceil(log2(n));
	int sz = 1 << (h + 1);
	segtree.resize(sz);

	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		int ix = lower_bound(tmp.begin(), tmp.end(), v[i]) - tmp.begin();

		ans += query(1, 0, n - 1, ix+1, n - 1);

		update(1, 0, n - 1, ix, 1);
	}
	cout << ans;

	return 0;
}
