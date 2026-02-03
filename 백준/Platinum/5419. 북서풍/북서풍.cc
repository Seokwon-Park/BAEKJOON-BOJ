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

int v[100005];
vector<ll> segtree;

ll getsum(int node, int st, int en, int l, int r)
{
	if (st > r || en < l) return 0;
	if (st >= l && en <= r) return segtree[node];


	int mid = (st + en) / 2;
	ll lres = getsum(node * 2, st, mid, l, r);
	ll rres = getsum(node * 2 + 1, mid + 1, en, l, r);

	return lres + rres;
}

void update(int node, int st, int en, int ix, int val)
{
	if (st > ix || en < ix) return;
	segtree[node]++;

	if (st != en)
	{
		int mid = (st + en) / 2;
		update(node * 2, st, mid, ix, val);
		update(node * 2 + 1, mid + 1, en, ix, val);
	}
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
		segtree.assign(n * 4, 0);

		vector<pii> xy(n);
		for (auto& [x, y] : xy)
		{
			cin >> x >> y;
		}
		sort(xy.begin(), xy.end(), [](const auto& a, const auto& b)
			{
				if (a.first == b.first)return a.second > b.second;
				return a.first < b.first;
			});


		vector<int> ysort(n);
		for (int i = 0; i < n; i++)
		{
			ysort[i] = xy[i].second;
		}
		sort(ysort.begin(), ysort.end());
		ysort.erase(unique(ysort.begin(), ysort.end()), ysort.end());

		ll ans = 0;
		for (int i = 0; i < n; i++)
		{
			v[i] = lower_bound(ysort.begin(), ysort.end(), xy[i].second) - ysort.begin();

			update(1, 0, ysort.size() - 1, v[i], 1);

			ans += getsum(1, 0, ysort.size() - 1, v[i], ysort.size() - 1) - 1;
		}

		cout << ans << '\n';
	}


	return 0;
}