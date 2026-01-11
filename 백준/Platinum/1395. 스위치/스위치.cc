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

void lazyupdate(int node, int st, int en)
{
	if (lazy[node])
	{
		segtree[node] = (en - st + 1) - segtree[node];
		if (st != en)
		{
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int st, int en, int l, int r)
{
	lazyupdate(node, st, en);
	if (en < l || st > r) return;
	if (st >= l && en <= r)
	{
		segtree[node] = (en - st + 1) - segtree[node];
		if (st != en)
		{
			lazy[node * 2] ^= 1;
			lazy[node * 2 + 1] ^= 1;
		}
		return;
	}
	int mid = (st + en) / 2;
	update(node * 2, st, mid, l, r);
	update(node * 2 + 1, mid + 1, en, l, r);
	segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

ll query(int node, int st, int en, int l, int r)
{
	lazyupdate(node, st, en);
	if (en < l || st > r) return 0;
	if (st >= l && en <= r) return segtree[node];

	int mid = (st + en) / 2;
	ll lres = query(node * 2, st, mid, l, r);
	ll rres = query(node * 2 + 1, mid + 1, en, l, r);

	return lres + rres;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	int h = ceil(log2(n));
	int sz = 1 << (1 + h);
	segtree.resize(sz);
	lazy.resize(sz);

	for (int i = 0; i < k; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0)
		{
			update(1, 0, n - 1, b - 1, c - 1);
		}
		else
		{
			cout << query(1, 0, n - 1, b - 1, c - 1) << '\n';
		}
	}


	return 0;
}