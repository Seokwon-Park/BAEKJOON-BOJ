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
ll v[1000005];

ll sum(int node, int st, int en, int l, int r)
{
	if (r < st || l > en) return 0;
	if (l <= st && en <= r) return segtree[node];

	int mid = (st + en) / 2;
	ll lres = sum(node * 2, st, mid, l, r);
	ll rres = sum(node * 2 + 1, mid + 1, en, l, r);

	return lres + rres;
}

void update(int node, int st, int en, int index, ll diff)
{
	if (index < st || index > en) return;
	segtree[node] += diff;

	if (st != en)
	{
		int mid = (st + en) / 2;
		update(node * 2, st, mid, index, diff);
		update(node * 2 + 1, mid + 1, en, index, diff);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	int h = ceil(log2(n));
	int sz = 1 << (h + 1);

	segtree.resize(sz);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		update(1, 0, n - 1, i, v[i]);
	}

	for (int i = 0; i < q; i++)
	{
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		if (x > y) swap(x, y);
		cout << sum(1, 0, n - 1, x-1, y-1) << '\n';
		update(1, 0, n - 1, a - 1, b - v[a-1]);
		v[a-1] = b;
	}

	return 0;
}
