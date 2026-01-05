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

ll v[100005];
vector<ll> segtree;
vector<ll> lazy;

ll make(int node, int st, int en)
{
	if (st == en) return segtree[node] = v[st];

	int mid = (st + en) / 2;
	ll lres = make(node * 2, st, mid);
	ll rres = make(node * 2 + 1, mid + 1, en);
	return segtree[node] = lres + rres;
}

void lazyupdate(int node, int st, int en)
{
	if (lazy[node])
	{
		segtree[node] = segtree[node] + (en - st + 1) * lazy[node];
		if (st != en)
		{
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int st, int en, int l, int r, ll diff)
{
	lazyupdate(node, st, en);
	if (st > r || en < l) return;
	if (l <= st && en <= r)
	{
		segtree[node] = segtree[node] + (en - st + 1) * diff;
		if (st != en)
		{
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}

	int mid = (st + en) / 2;
	update(node * 2, st, mid, l, r, diff);
	update(node * 2 + 1, mid + 1, en, l, r, diff);
	segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

ll query(int node, int st, int en, int ix)
{
	lazyupdate(node, st, en);
	if (ix < st || ix > en) return 0;
	if (st == en) return segtree[node];

	int mid = (st + en) / 2;
	ll lres = query(node * 2, st, mid, ix);
	ll rres = query(node * 2 + 1, mid + 1, en, ix);
	return lres + rres;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int h = ceil(log2(n));
	int sz = 1 << (h + 1);

	segtree.resize(sz);
	lazy.resize(sz);

	make(1, 0, n - 1);
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int q;
		cin >> q;
		if (q == 1)
		{
			int a, b, c;
			cin >> a >> b >> c;
			update(1, 0, n - 1, a - 1, b - 1, c);
		}
		else
		{
			int x;
			cin >> x;
			cout << query(1, 0, n - 1, x - 1) << '\n';
		}
	}



	return 0;
}