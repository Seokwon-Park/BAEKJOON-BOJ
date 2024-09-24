#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

vector<pii> segTree;
int v[100005];
pii InitTree(int st, int en, int node)
{
	int mid = (st + en) / 2;
	if (st == en) return segTree[node] = { v[st], v[st]};
	auto[lmin, lmax] = InitTree(st, mid, node * 2);
	auto[rmin, rmax] = InitTree(mid + 1, en, node * 2 + 1);
	int mn = min(lmin, rmin);
	int mx = max(lmax, rmax);
	return segTree[node] = { mn, mx };
}

pii FindValue(int st, int en, int node, int l, int r)
{
	if (en < l || st > r)return { INF, 0 };
	if (l <= st && r >= en)return segTree[node];

	int mid = (st + en) / 2;
	auto [lmin, lmax] = FindValue(st, mid, node * 2, l, r);
	auto [rmin, rmax] = FindValue(mid + 1, en, node * 2 + 1, l, r);
	int mn = min(lmin, rmin);
	int mx = max(lmax, rmax);
	return { mn, mx };
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int height = ceil(log2(n));
	int sz = 1 << (height + 1);
	segTree.resize(sz);

	InitTree(0, n - 1, 1);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		// 0-indexed
		a--;
		b--;
		auto [x, y] = FindValue(0, n - 1, 1, a, b);
		cout << x << ' ' << y << '\n';
	}

	return 0;
}

