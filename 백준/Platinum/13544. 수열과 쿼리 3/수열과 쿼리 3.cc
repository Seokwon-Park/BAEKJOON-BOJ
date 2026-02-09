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

vector<vector<ll>> segtree;
int v[100000];

void init(int node, int st, int en)
{
	if (st == en)
	{
		segtree[node] = { v[st] };
		return;
	}
	int mid = (st + en) / 2;
	init(node * 2, st, mid);
	init(node * 2 + 1, mid + 1, en);
	segtree[node].resize(segtree[node * 2].size() + segtree[node * 2 + 1].size());
	merge(segtree[node * 2].begin(), segtree[node * 2].end(),
		segtree[node * 2 + 1].begin(), segtree[node * 2 + 1].end(),
		segtree[node].begin());
}

int query(int node, int st, int en, int l, int r, int k) // k 라는 값보다 작거나 같은 값의 개수를 찾는 쿼리
{
	if (en <l || st >r) return 0;
	if (st >= l && en <= r) return segtree[node].end() -  upper_bound(segtree[node].begin(), segtree[node].end(), k);

	int mid = (st + en) / 2;
	return query(node * 2, st, mid, l, r, k) + query(node * 2 + 1, mid + 1, en, l, r, k);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n;

	int h = ceil(log2(n));
	int sz = 1 << (1 + h);

	segtree.resize(sz);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	init(1, 0, n - 1);

	cin >> q;
	int lastans = 0;
	for (int i = 0; i < q; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a ^= lastans;
		b ^= lastans;
		c ^= lastans;

		lastans = query(1, 0, n - 1, a - 1, b - 1, c);

		cout << lastans << '\n';
	}

	return 0;
}
