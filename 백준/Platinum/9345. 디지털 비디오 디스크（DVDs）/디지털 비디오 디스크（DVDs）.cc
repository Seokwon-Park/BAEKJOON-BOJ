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

vector<pii> segtree;
vector<pii> v;

pii getRange(pii a, pii b)
{
	pii ret;
	ret.first = min(a.first, b.first);
	ret.second = max(a.second, b.second);
	return ret;
}

void update(int node, int st, int en, int ix)
{
	if (st > ix || en < ix) return;
	if (st != en)
	{
		int mid = (st + en) / 2;
		update(node * 2, st, mid, ix);
		update(node * 2 + 1, mid + 1, en, ix);
		segtree[node] = getRange(segtree[node * 2], segtree[node * 2 + 1]);
		return;
	}
	segtree[node] = v[ix];
}

pii query(int node, int st, int en, int l, int r)
{
	if (en < l || st > r) return { INF, 0 };
	if (st >= l && en <= r) return segtree[node];
	int mid = (st + en) / 2;
	return getRange(query(node * 2, st, mid, l, r), query(node * 2 + 1, mid + 1, en, l, r));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int h = ceil(log2(n));
		int sz = 1 << (1 + h);
		segtree.assign(sz, { INF , 0 });
		v.assign(n, { 0,0 });

		for (int i = 0; i < n; i++)
		{
			v[i] = { i, i };
			update(1, 0, n - 1, i);
		}

		for (int i = 0; i < k; i++)
		{
			int q, a, b;
			cin >> q >> a >> b;
			if (q == 1)
			{
				auto [x, y] = query(1, 0, n - 1, a, b);
				cout << (x == a && y == b ? "YES" : "NO") << '\n';
			}
			else
			{
				swap(v[a], v[b]);
				update(1, 0, n - 1, a);
				update(1, 0, n - 1, b);
			}
		}
	}

	return 0;
}