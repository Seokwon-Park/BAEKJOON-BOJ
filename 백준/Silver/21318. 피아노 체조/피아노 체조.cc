#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int diff[100005];
vector<int> segTree;
int n;

int Init(int node, int st, int en)
{
	if (st == en)
	{
		if (st < n - 1 && diff[st] > diff[st + 1])
		{
			return segTree[node] = 1;
		}
		else
		{
			return segTree[node] = 0;
		}
	}
	int mid = (st + en) / 2;
	int Lval = Init(node * 2, st, mid);
	int Rval = Init(node * 2 + 1, mid + 1, en);

	return segTree[node] = Lval + Rval;
}

int GetSum(int node, int st, int en, int l, int r)
{
	if (en < l || st > r) return 0;
	if (l <= st && en <= r) return segTree[node];

	int mid = (st + en) / 2;
	int Lval = GetSum(node * 2, st, mid, l, r);
	int Rval = GetSum(node * 2 + 1, mid + 1, en, l, r);
	return Lval + Rval;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> diff[i];
	}
	int height = ceil(log2(n));
	int sz = 1 << (height + 1);

	segTree.resize(sz);
	Init(1, 0, n - 1);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		int res = GetSum(1, 0, n - 1, a, b);
		if (b + 1 < n && diff[b] > diff[b+1])
		{
			res -= 1;
		}
		cout << res << '\n';
	}


	return 0;
}
