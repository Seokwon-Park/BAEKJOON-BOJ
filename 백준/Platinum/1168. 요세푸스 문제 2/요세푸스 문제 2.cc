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
int v[100000];

int init(int node, int st, int en)
{
	if (st == en) return segtree[node] = v[st];
	int mid = (st + en) / 2;
	return segtree[node] = init(node * 2, st, mid) + init(node * 2 + 1, mid + 1, en);
}

void update(int node, int st, int en, int ix)
{
	if (ix < st || ix > en)return;
	segtree[node]--;

	if (st != en)
	{
		int mid = (st + en) / 2;
		update(node * 2, st, mid, ix);
		update(node * 2 + 1, mid + 1, en, ix);
	}
}

int query(int node, int st, int en, int order)
{
	if (st == en) return st;

	int mid = (st + en) / 2;
	int l = segtree[node * 2];
	if (l > order)
	{
		return query(node * 2, st, mid, order);
	}
	else
	{
		return query(node * 2 + 1, mid + 1, en, order - l);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	fill(v, v + n, 1);
	int h = ceil(log2(n));
	int sz = 1 << (1 + h);

	segtree.resize(sz, 0);
	fill(v, v + n, 1);

	init(1, 0, n - 1);

	int index = 0;
	cout << '<';
	for (int i = 0; i < n; i++)
	{
		index = (index + k - 1) % (n - i);

		int x = query(1, 0, n - 1, index);
		cout << x + 1;
		if (i < n - 1) cout << ", ";

		update(1, 0, n - 1, x);
	}
	cout << '>';

	return 0;
}