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

void update(int node, int st, int en, int ix)
{
	if (ix < st || ix > en)return;
	segtree[node]++;

	if (st != en)
	{
		int mid = (st + en) / 2;
		update(node * 2, st, mid, ix);
		update(node * 2 + 1, mid + 1, en, ix);
	}
}

ll query(int node, int st, int en, int l, int r)
{
	if (en < l || st > r) return 0;
	if (st >= l && en <= r) return segtree[node];

	int mid = (st + en) / 2;
	int lres = query(node * 2, st, mid, l, r);
	int rres = query(node * 2 + 1, mid + 1, en, l, r);

	return lres + rres;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int h = ceil(log2(n));
	int sz = 1 << (h + 1);
	segtree.resize(sz);

	vector<int> v(n);
	vector<int> uni(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		uni[i] = v[i];
	}
	sort(uni.begin(), uni.end());

	uni.erase(unique(uni.begin(), uni.end()), uni.end());
	vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		int ix = lower_bound(uni.begin(), uni.end(), v[i]) - uni.begin();

		int rank = query(1, 0, n - 1, ix + 1, n - 1) + 1;
		ans.push_back(rank);

		update(1, 0, n - 1, ix);
	}

	for (auto i : ans)cout << i << '\n';



	return 0;
}