#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int v[100005];
vector<ll> segtree;

void update(int node, int st, int en, int ix, int diff)
{
	if (ix < st || ix >en) return;
	segtree[node] += diff;
	if (st != en)
	{
		int mid = (st + en) / 2;
		update(node * 2, st, mid, ix, diff);
		update(node * 2 + 1, mid + 1, en, ix, diff);
	}
}

ll query(int node, int st, int en, int l, int r)
{
	if (st > r || en < l) return 0;
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
	segtree.assign(sz, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		update(1, 0, n - 1, i, v[i]);
	}

	int m;
	cin >> m;
	vector<vector<int>> updates;
	vector<vector<int>> queries;
	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		if (k == 1)
		{
			int a, b;
			cin >> a >> b;
			updates.push_back({ a,b });
		}
		else
		{
			int a, b, c;
			cin >> a >> b >> c;
			queries.push_back({ a, b, c, i });
		}
	}
	sort(queries.begin(), queries.end());

	vector<pair<int, ll>> res;
	int cur = 0;
	for (int i = 0; i < updates.size(); i++)
	{
		while (cur < queries.size() && queries[cur][0] <= i)
		{
			int b = queries[cur][1];
			int c = queries[cur][2];
			int loc = queries[cur][3];
			res.push_back({ loc, query(1, 0, n - 1, b - 1, c - 1) });
			cur++;
		}
		int a = updates[i][0];
		int b = updates[i][1];
		a--;
		ll diff = b - v[a];
		update(1, 0, n - 1, a, diff);
		v[a] = b;
	}
	while (cur < queries.size())
	{
		int b = queries[cur][1];
		int c = queries[cur][2];
		int loc = queries[cur][3];
		res.push_back({ loc, query(1, 0, n - 1, b - 1, c - 1) });
		cur++;
	}

	sort(res.begin(), res.end());
	for (auto [a, b] : res)
	{
		cout << b << '\n';
	}

	return 0;
}