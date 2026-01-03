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
vector<ll> v;

ll sum(int node, int st, int en, int l, int r)
{
	if (en < l || st > r) return 0;
	if (st >= l && en <= r) return segtree[node];

	int mid = (st + en) / 2;
	ll lres = sum(node * 2, st, mid, l, r);
	ll rres = sum(node * 2+1, mid+1, en, l, r);

	return lres + rres;
}

void update(int node, int st, int en, int ix, ll diff)
{
	if (ix < st || ix > en) return;
	segtree[node] += diff;

	if (st != en)
	{
		int mid = (st + en) / 2;
		update(node * 2, st, mid, ix, diff);
		update(node * 2 + 1, mid + 1, en, ix, diff);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int h = ceil(log2(n));
	int sz = 1 << (h + 1);

	v.resize(n);
	segtree.resize(sz);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0)
		{
			if (b > c) swap(b, c);
			cout << sum(1, 0, n - 1, b - 1, c - 1) << '\n';
		}
		else
		{
			ll diff = c - v[b - 1];
			v[b - 1] = c;
			update(1, 0, n - 1, b - 1, diff);
		}
	}

	return 0;
}