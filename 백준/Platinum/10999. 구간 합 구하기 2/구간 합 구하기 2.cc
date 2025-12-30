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

vector<ll> lazy;
vector<ll> segtree;
ll v[1000005];

ll make(int node, int st, int en)
{
	if (st == en) return segtree[node] = v[st];

	int mid = (st + en) / 2;
	ll l = make(node * 2, st, mid);
	ll r = make(node * 2 + 1, mid + 1, en);

	return segtree[node] = l + r;
}

void lazyupdate(int node, int st, int en)
{
	if (lazy[node] != 0)
	{
		segtree[node] = segtree[node] + (en - st + 1) * lazy[node];
		if (st != en)
		{
			lazy[node * 2] = lazy[node * 2] + lazy[node];
			lazy[node * 2 + 1] = lazy[node * 2 + 1] + lazy[node];
		}
		lazy[node] = 0;
	}
}

ll sum(int node, int st, int en, int l, int r)
{
	lazyupdate(node, st, en);
	if (l > en || r < st) return 0;
	if (l <= st && en <= r) return segtree[node];

	int mid = (st + en) / 2;
	ll lres = sum(node*2, st, mid, l, r);
	ll rres = sum(node*2+1, mid + 1, en, l, r);
	return lres + rres;
}

void update(int node, int st, int en, int l, int r, ll diff)
{
	lazyupdate(node, st, en);
	if (l > en || r < st) return;
	if (l <= st && en <= r)
	{
		segtree[node] = segtree[node] + (en - st + 1) * diff;
		if (st != en)
		{
			lazy[node * 2] = lazy[node * 2] + diff;
			lazy[node * 2 + 1] = lazy[node * 2 + 1] + diff;
		}
		return;
	}

	int mid = (st + en) / 2;
	update(node * 2, st, mid, l, r, diff);
	update(node * 2 + 1, mid + 1, en, l, r, diff);
	segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int height = ceil(log2(n));
	int sz = 1 << (height + 1);

	segtree.resize(sz);
	lazy.resize(sz);

	make(1, 0, n - 1);

	for (int i = 0; i < m + k; i++)
	{
		ll a, b,c,d;
		cin >> a;
		if (a == 1)
		{
			cin >> b >> c >> d;
			update(1, 0, n - 1, b - 1, c - 1, d);
		}
		else
		{
			cin >> b >> c;
			cout << sum(1, 0, n - 1, b - 1, c - 1) << '\n';
		}
	}


	return 0;
}