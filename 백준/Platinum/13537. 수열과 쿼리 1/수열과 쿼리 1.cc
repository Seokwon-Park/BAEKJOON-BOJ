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
using hashmap = unordered_map<key, value>;

vector<vector<int>> segtree;
int v[100005];

void maketree(int node, int st, int en)
{
	if (st == en)
	{
		segtree[node].push_back(v[st]);
		return;
	}

	int mid = (st + en) / 2;
	maketree(node * 2, st, mid);
	maketree(node * 2 + 1, mid + 1, en);
	segtree[node].resize(segtree[node * 2].size() + segtree[node * 2 + 1].size());
	merge(segtree[node * 2].begin(), segtree[node * 2].end(),
		segtree[node * 2 + 1].begin(), segtree[node * 2 + 1].end(),
		segtree[node].begin());
}

int query(int node, int st, int en, int l, int r, int k)
{
	if (st > r || en < l) return 0;
	if (st >= l && en <= r)
	{
		return segtree[node].end() - upper_bound(segtree[node].begin(), segtree[node].end(), k);
	}
	int mid = (st + en) / 2;
	return query(node * 2, st, mid, l, r, k) + query(node * 2 + 1, mid + 1, en, l, r, k);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int h = ceil(log2(n));
	int sz = 1 << (1 + h);
	segtree.resize(sz);

	maketree(1, 0, n - 1);

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		cout << query(1, 0, n - 1, a - 1, b - 1, c) << '\n';
	}


	return 0;
}