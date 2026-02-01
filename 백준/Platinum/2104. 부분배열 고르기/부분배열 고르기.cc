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

int n;
int v[100005];
vector<ll> segtree;
vector<ll> mintree;

void maketree(int node, int st, int en)
{
	if (st == en)
	{
		segtree[node] = v[st];
		mintree[node] = st;
		return;
	}

	int mid = (st + en) / 2;
	maketree(node * 2, st, mid);
	maketree(node * 2 + 1, mid + 1, en);

	segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
	int lmin = v[mintree[node * 2]];
	int rmin = v[mintree[node * 2 + 1]];
	if (lmin < rmin)
	{
		mintree[node] = mintree[node * 2];
	}
	else
	{
		mintree[node] = mintree[node * 2 + 1];
	}
}

ll getsum(int node, int st, int en, int l, int r)
{
	if (st > r || en < l) return 0;
	if (st >= l && en <= r) return segtree[node];

	int mid = (st + en) / 2;
	ll lres = getsum(node * 2, st, mid, l, r);
	ll rres = getsum(node * 2 + 1, mid + 1, en, l, r);

	return lres + rres;
}

int getmin(int node, int st, int en, int l, int r)
{
	if (st > r || en < l) return -1;
	if (st >= l && en <= r) return mintree[node];

	int mid = (st + en) / 2;
	int lix = getmin(node * 2, st, mid, l, r);
	int rix = getmin(node * 2 + 1, mid + 1, en, l, r);

	int lval, rval;
	if (lix == -1) lval = INF;
	else lval = v[lix];
	if (rix == -1) rval = INF;
	else rval = v[rix];
	

	if (lval < rval)
	{
		return lix;
	}
	else
	{
		return rix;
	}
}

ll getmaxarea(int l, int r)
{
	ll sum = getsum(1, 0, n - 1, l, r);
	int min_ix = getmin(1, 0, n - 1, l, r);
	ll res = sum * v[min_ix];

	if (l < min_ix)
	{
		res = max(res, getmaxarea(l, min_ix - 1));
	}
	if (min_ix < r)
	{
		res = max(res, getmaxarea(min_ix + 1, r));
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int h = ceil(log2(n));
	int sz = 1 << (1 + h);
	segtree.resize(sz);
	mintree.resize(sz);

	maketree(1, 0, n - 1);

	cout << getmaxarea(0, n - 1);

	return 0;
}