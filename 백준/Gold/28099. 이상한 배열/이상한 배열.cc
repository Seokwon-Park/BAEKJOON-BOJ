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

ll segtree[200005 * 4];
ll v[200005];

ll make(int node, int st, int en)
{
	if (st == en)return segtree[node] = v[st];
	int mid = (st + en) / 2;
	ll l = make(node * 2, st, mid);
	ll r = make(node * 2 + 1, mid + 1, en);
	return segtree[node] = max(l, r);
}

ll getmax(int node, int st, int en, int l, int r)
{
	if (st > r || en < l) return 0;
	if (st >= l && en <= r) return segtree[node];
	int mid = (st + en) / 2;
	ll lres = getmax(node * 2, st, mid, l, r);
	ll rres = getmax(node * 2 + 1, mid + 1, en, l, r);
	return max(lres, rres);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		make(1, 0, n - 1);

		map<int, pii> query;
		bool isweird = true;
		for (int i = 0; i < n; i++)
		{
			int x = v[i];
			if (query.find(x) == query.end())
			{
				query[x] = { i,0 };
			}
			query[x].second = max(query[x].second, i);
		}
		for (auto [key, val] : query)
		{
			auto [st, en] = val;
			int mx = getmax(1, 0, n - 1, st, en);
			if (mx > key)
			{
				isweird = false;
				break;
			}
		}
		cout << (isweird ? "Yes" : "No") << '\n';

	}

	return 0;
}