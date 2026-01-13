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
vector<ll> lazy;
vector<ll> v;

ll maketree(int node, int st, int en)
{
	if (st == en) return segtree[node] ^= v[st];
	int mid = (st + en) / 2;
	return segtree[node] = maketree(node * 2, st, mid) ^ maketree(node * 2 + 1, mid + 1, en);
}

void lazyupdate(int node, int st, int en)
{
	if (lazy[node])
	{
		if ((en - st + 1) % 2)
		{
			segtree[node] ^= lazy[node];
		}
		if (st != en)
		{
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int st, int en, int l, int r, int val)
{
	lazyupdate(node, st, en);
	if (st > r || en < l) return;
	if (st >= l && en <= r)
	{
		if ((en - st + 1) % 2)
		{
			segtree[node] ^= val;
		}
		if (st != en)
		{
			lazy[node * 2] ^= val;
			lazy[node * 2 + 1] ^= val;
		}
		return;
	}
	int mid = (st + en) / 2;
	update(node * 2, st, mid, l, r, val);
	update(node * 2+1, mid+1, en, l, r, val);
	segtree[node] = segtree[node * 2] ^ segtree[node * 2 + 1];
}

ll query(int node, int st, int en, int l, int r)
{
	lazyupdate(node, st, en);
	if (st > r || en < l) return 0;
	if (st >= l && en <= r) return segtree[node];

	int mid = (st + en) / 2;
	return query(node * 2, st, mid, l, r) ^ query(node * 2 + 1, mid + 1, en, l, r);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int h = ceil(log2(n));
	int sz = 1 << (1 + h);
	segtree.resize(sz);
	lazy.resize(sz);
	maketree(1, 0, n - 1);

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c, d;
		cin >> a;
		if (a == 2)
		{
			cin >> b >> c;
			cout << query(1, 0, n - 1, b, c) << '\n';
		}
		else
		{
			cin >> b >> c >> d;
			update(1, 0, n - 1, b, c, d);
		}
	}

	return 0;
}