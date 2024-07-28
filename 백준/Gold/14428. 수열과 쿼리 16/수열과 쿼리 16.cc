#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

vector<ll> segTree;
int v[100005];


int Init(int node, int l, int r)
{
	if (l == r) return segTree[node] = l;
	int mid = (l + r) / 2;
	int lix = Init(node * 2, l, mid);
	int rix = Init(node * 2 + 1, mid + 1, r);

	if (v[lix] <= v[rix])
	{
		return segTree[node] = lix;
	}
	else
	{
		return segTree[node] = rix;
	}
}

int GetMinIdx(int node, int l, int r, int i, int j)
{
	if (i > r || j < l) return 0;
	if (i <= l && r <= j) return segTree[node];

	int mid = (l + r) / 2;
	int lix = GetMinIdx(node * 2, l, mid, i, j);
	int rix = GetMinIdx(node * 2 + 1, mid + 1, r, i, j);
	if (v[lix] <= v[rix])
	{
		return lix;
	}
	else
	{
		return rix;
	}
}

void Update(int node, int l, int r, int idx)
{
	if (idx > r || idx < l || l == r) return;

	int mid = (l + r) / 2;
	Update(node * 2, l, mid, idx);
	Update(node * 2+1, mid + 1, r, idx);
	if (v[segTree[node * 2]] <= v[segTree[node * 2 + 1]])
	{
		segTree[node] = segTree[node * 2];
	}
	else
	{
		segTree[node] = segTree[node * 2 + 1];
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	v[0] = INF;
	int height = ceil(log2(n));
	int sz = 1 << (height+1);

	segTree.resize(sz);

	Init(1, 1, n);

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int cmd;
		cin >> cmd;
		if (cmd == 1)
		{
			int ix, k;
			cin >> ix >> k;
			v[ix] = k;
			Update(1, 1, n, ix);
		}
		else
		{
			int st, en;
			cin >> st >> en;
			cout << GetMinIdx(1, 1, n, st, en) << '\n';
		}
	}



	return 0;
}