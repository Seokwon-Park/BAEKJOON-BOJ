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

vector<int> segtree;
vector<pii> v;

void update(int node, int st, int en, int ix)
{
	if (ix < st || ix > en)return;
	segtree[node]++;

	if (st != en)
	{
		int mid = (st + en) / 2;
		update(node * 2, st, mid, ix);
		update(node * 2 + 1, mid + 1, en, ix);
	}
}

ll query(int node, int st, int en, int l, int r)
{
	if (st > r || en < l)return 0;
	if (st >= l && en <= r) return segtree[node];

	int mid = (st + en) / 2;
	return query(node * 2, st, mid, l, r) + query(node * 2 + 1, mid + 1, en, l, r);
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		int n, m, k;
		cin >> n >> m >> k;
		int h = ceil(log2(m));
		int sz = 1 << (1 + h);
		v.assign(k, { 0,0 });
		segtree.assign(sz, 0);
		for (int i = 0; i < k; i++)
		{
			int a, b;
			cin >> a >> b;
			v[i] = { a - 1,b - 1 };
		}

		sort(v.begin(), v.end());

		ll ans = 0;
		for (int i = 0; i < k; i++)
		{
			auto [a, b] = v[i];
			update(1, 0, m - 1, b);
			ans += query(1, 0, m - 1, b + 1, m - 1);
		}

		cout << "Test case " << tc << ": " << ans << '\n';
	}

	return 0;
}