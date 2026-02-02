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

int n;
int v[100005];
vector<ll> oddtree;
vector<ll> eventree;

void maketree(int node, int st, int en)
{
	if (st == en)
	{
		oddtree[node] = v[st] % 2;
		eventree[node] = (v[st] + 1) % 2;
		return;
	}

	int mid = (st + en) / 2;
	maketree(node * 2, st, mid);
	maketree(node * 2 + 1, mid + 1, en);

	oddtree[node] = oddtree[node * 2] + oddtree[node * 2 + 1];
	eventree[node] = eventree[node * 2] + eventree[node * 2 + 1];
}

ll getsum(int node, int st, int en, int l, int r, bool isodd)
{
	if (st > r || en < l) return 0;
	if (st >= l && en <= r)
	{
		if (isodd) return oddtree[node];
		else return eventree[node];
	}

	int mid = (st + en) / 2;
	ll lres = getsum(node * 2, st, mid, l, r, isodd);
	ll rres = getsum(node * 2 + 1, mid + 1, en, l, r, isodd);

	return lres + rres;
}

void update(int node, int st, int en, int ix, int val)
{
	if (st > ix || en < ix) return;
	if (st == en)
	{
		oddtree[node] = val % 2;
		eventree[node] = (val + 1) % 2;
		return;
	}
	int mid = (st + en) / 2;
	update(node * 2, st, mid, ix, val);
	update(node * 2 + 1, mid + 1, en, ix, val);
	oddtree[node] = oddtree[node * 2] + oddtree[node * 2 + 1];
	eventree[node] = eventree[node * 2] + eventree[node * 2 + 1];
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int h = ceil(log2(n));
	int sz = 1 << (1 + h);
	oddtree.resize(sz);
	eventree.resize(sz);

	maketree(1, 0, n - 1);

	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			v[b - 1] = c;
			update(1, 0, n - 1, b - 1, c);
		}
		else if (a == 2)
		{
			cout << getsum(1, 0, n - 1, b - 1, c - 1, false) << '\n';
		}
		else
		{
			cout << getsum(1, 0, n - 1, b - 1, c - 1, true) << '\n';
		}
	}



	return 0;
}