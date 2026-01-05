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
vector<ll> lazy;
ll v[100005];

int tts(string str)
{
	int h = stoi(str.substr(0, 2));
	int m = stoi(str.substr(3, 2));
	int s = stoi(str.substr(6, 2));

	return h * 3600 + m * 60 + s;
}

void lazyupdate(int node, int st, int en)
{
	if (lazy[node])
	{
		segtree[node] += (en - st + 1) * lazy[node];
		if (st != en)
		{
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int st, int en, int l, int r, ll val)
{
	lazyupdate(node, st, en);
	if (st > r || en < l) return;
	if (st >= l && en <= r)
	{
		segtree[node] += (en - st + 1) * val;
		if (st != en)
		{
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}
	int mid = (st + en) / 2;
	update(node * 2, st, mid, l, r, val);
	update(node * 2 + 1, mid + 1, en, l, r, val);
	segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}



ll query(int node, int st, int en, int l, int r)
{
	lazyupdate(node, st, en);
	if (st > r || en < l) return 0;
	if (st >= l && en <= r) return segtree[node];
	int mid = (st + en) / 2;
	ll lres = query(node * 2, st, mid, l, r);
	ll rres = query(node * 2 + 1, mid + 1, en, l, r);
	return lres + rres;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int range = 24 * 3600;
	int h = ceil(log2(range));
	int sz = 1 << (h + 1);
	segtree.resize(sz);
	lazy.resize(sz);

	for (int i = 0; i < n; i++)
	{
		string s, e;
		char c;
		cin >> s >> c >> e;
		int st = tts(s);
		int en = tts(e);
		if (st <= en)
		{
			update(1, 0, range - 1, st, en, 1);
		}
		else
		{
			update(1, 0, range - 1, st, range - 1, 1);
			update(1, 0, range - 1, 0, en, 1);
		}
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		string s, e;
		char c;
		cin >> s >> c >> e;
		int st = tts(s);
		int en = tts(e);
		ll res = 0;
		ll total = 0;
		if (st <= en)
		{
			res = query(1, 0, range - 1, st, en);
			total = en - st + 1;
		}
		else
		{
			res = query(1, 0, range - 1, st, range - 1);
			res += query(1, 0, range - 1, 0, en);
			total = (en - st + 1) + range;
			
		}
		cout << fixed << setprecision(6) << (double)res / total << '\n';
	}




	return 0;
}