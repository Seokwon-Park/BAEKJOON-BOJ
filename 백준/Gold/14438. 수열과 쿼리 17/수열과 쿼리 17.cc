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
vector<int> v;

int make(int node, int st, int en)
{
	if (st == en) return segtree[node] = v[st];

	int mid = (st + en) / 2;
	int lres = make(node * 2, st, mid);
	int rres = make(node * 2 + 1, mid + 1, en);

	return segtree[node] = min(lres, rres);
}

int getmin(int node, int st, int en, int l, int r)
{
	if (en < l || st > r) return INF;
	if (st >= l && en <= r) return segtree[node];

	int mid = (st + en) / 2;
	int lres = getmin(node * 2, st, mid, l, r);
	int rres = getmin(node * 2 + 1, mid + 1, en, l, r);

	return min(lres, rres);
}

int update(int node, int st, int en, int ix, int val)
{
	if (ix < st || ix > en) return segtree[node];
	if (st == en)
	{
		if (st == ix)
		{
			return segtree[node] = v[st];
		}
		else
		{
			return segtree[node];
		}
	}

	int mid = (st + en) / 2;
	int lres = update(node * 2, st, mid, ix, val);
	int rres = update(node * 2 + 1, mid + 1, en, ix, val);

	return segtree[node] = min(lres, rres);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n;

	v.resize(n);
	int h = ceil(log2(n));
	int sz = 1 << (h + 1);
	segtree.resize(sz, INF);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	make(1, 0, n - 1);

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 2)
		{
			cout << getmin(1, 0, n - 1, b - 1, c - 1) << '\n';
		}
		else
		{
			v[b - 1] = c;
			update(1, 0, n - 1, b - 1, c);
		}
	}

	return 0;
}