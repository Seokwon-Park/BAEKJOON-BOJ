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

vector<int> segtree;

void update(int node, int st, int en, int ix)
{
	if (st > ix || en < ix) return;
	segtree[node]++;
	if (st != en)
	{
		int mid = (st + en) / 2;
		update(node * 2, st, mid, ix);
		update(node * 2 + 1, mid + 1, en, ix);
	}
}

int query(int node, int st, int en, int l, int r)
{
	if (en < l || st > r) return 0;
	if (st >= l && en <= r) return segtree[node];
	int mid = (st + en) / 2;
	return query(node * 2, st, mid, l, r) + query(node * 2 + 1, mid + 1, en, l, r);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int h = ceil(log2(n));
	int sz = 1 << (1 + h);
	segtree.resize(sz);

	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		x--;
		update(1, 0, n - 1, x);
		ans += query(1, 0, n - 1, x + 1, n - 1);
	}

	cout << ans;
	
	return 0;
}