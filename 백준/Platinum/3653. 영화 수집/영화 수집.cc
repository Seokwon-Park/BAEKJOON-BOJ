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

vector<ll> segtree;
vector<ll> loc;

void update(int node, int st, int en, int ix, int val)
{
	if (ix < st || ix > en) return;
	segtree[node] += val;

	if (st != en)
	{
		int mid = (st + en) / 2;
		update(node * 2, st, mid, ix, val);
		update(node * 2 + 1, mid + 1, en, ix, val);
	}
}

ll sum(int node, int st, int en, int l, int r)
{
	if (st > r || en < l) return 0;
	if (st >= l && en <= r) return segtree[node];

	int mid = (st + en) / 2;
	return sum(node * 2, st, mid, l, r) + sum(node * 2 + 1, mid + 1, en, l, r);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		segtree.clear();
		loc.clear();
		int n, m;
		cin >> n >> m;
		int h = ceil(log2(n + m + 1));
		int sz = 1 << (h + 1);
		segtree.resize(sz);
		loc.resize(n + 1);
		for (int i = 0; i < n; i++)
		{
			loc[i] = n - i - 1;
			update(1, 0, n + m - 1, i, 1);
		}

		for (int i = 0; i < m; i++)
		{
			int x;
			cin >> x;
			int xloc = loc[x - 1];
			cout << sum(1, 0, n + m - 1, xloc + 1, n + m - 1) << ' ';
			update(1, 0, n + m - 1, xloc, -1);
			update(1, 0, n + m - 1, n+i, 1);
			loc[x - 1] = n + i;
		}
		cout << '\n';
	}


	return 0;
}
