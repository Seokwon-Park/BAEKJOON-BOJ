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

ll segtree[100005 * 4];
ll v[100005];

void update(int node, int st, int en, int ix, ll val)
{
	if (st > ix || en < ix) return;
	if (st == en)
	{
		if (val != 0)
		{
			val = val > 0 ? 1 : -1;
		}
		segtree[node] = val;
		return;
	}
	int mid = (st + en) / 2;
	update(node * 2, st, mid, ix, val);
	update(node * 2 + 1, mid + 1, en, ix, val);
	segtree[node] = segtree[node * 2] * segtree[node * 2 + 1];
}



ll query(int node, int st, int en, int l, int r)
{
	if (st > r || en < l) return 1;
	if (st >= l && en <= r) return segtree[node];
	int mid = (st + en) / 2;
	ll lres = query(node * 2, st, mid, l, r);
	ll rres = query(node * 2 + 1, mid + 1, en, l, r);
	return lres * rres;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	while (cin >> n >> k)
	{
		string ans;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
			update(1, 0, n - 1, i, v[i]);
		}
		for (int i = 0; i < k; i++)
		{
			char c;
			int a, b;
			cin >> c >> a >> b;
			if (c == 'C')
			{
				update(1, 0, n - 1, a - 1, b);
			}
			else
			{
				int res = query(1, 0, n - 1, a - 1, b - 1);
				if (res == 0)
				{
					ans += '0';
				}
				else if (res > 0)
				{
					ans += '+';
				}
				else
				{
					ans += '-';
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}