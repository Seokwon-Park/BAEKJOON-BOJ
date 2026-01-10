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

void update(int node, int st, int en, int ix, int diff)
{
	if (ix< st || en <ix) return;
	segtree[node] += diff;
	if (st != en)
	{
		int mid = (st + en) / 2;
		update(node * 2, st, mid, ix, diff);
		update(node * 2 + 1, mid + 1, en, ix, diff);
	}
}

int query(int node, int st, int en, int rank)
{
	if (st == en) return st;
	int mid = (st + en) / 2;
	if (rank <= segtree[node * 2])
	{
		return query(node * 2, st, mid, rank);
	}
	else
	{
		return query(node * 2 + 1, mid + 1, en, rank - segtree[node * 2]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int h = ceil(log2(1000005));
	int sz = 1 << (h + 1);
	segtree.resize(sz);
	
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a;
		if (a == 1)
		{
			cin >> b;
			int res = query(1, 1, 1000005, b);
			cout << res << '\n';
			update(1, 1, 1000005, res, -1);
		}
		else
		{
			cin >> b >> c;
			update(1, 1, 1000005, b, c);
		}
	}



	return 0;
}